#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<sstream>
using namespace std;

struct student
{
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 scores average
};

void scoreList(int* list,istringstream &iss);
student* studenList(string id,string stu_name,int* score_list,int n,double ave,student* student_ptr,int l); 

double top_ten_ave(int* score_list,int n)
{
    double ave=0;
    if(n<=10)
    {
        for(int i=0;i<n;i++)
        {
            ave+=score_list[i];
        }
        ave/=n;
        return ave;
    }
    else
    {
        int count=0;
        int* temp=new int[n];
        for(int i=0;i<n;i++)
        {
            temp[i]=score_list[i];
        }
        
        for(int j=1;j<n;j++)
        {
            int key=temp[j];
            int i=j-1;
            while((i>=0)&&(temp[i]>key))
            {
                temp[i+1]=temp[i];
                i=i-1;
            }
            temp[i+1]=key;
        }

        for(int i=n-10;i<n;i++)
        {
            //cout<<temp[i]<<" ";
            ave+=temp[i];
        }
        //cout<<endl;
        ave/=10;
        delete [] temp;
        return ave;
    }
}

double stdev(student* student_ptr,int l)
{
    //double* aveptr= new double[l];
    double ave_ave=0;

    for(int i=0;i<l;i++)
    {
        //cout<<student_ptr[i].average<<endl;
        ave_ave+=student_ptr[i].average;
    }
    ave_ave/=l;

    double std=0;
    for(int i=0;i<l;i++)
    {
        std+=pow((student_ptr[i].average-ave_ave),2);
    }
    std/=l;
    std=sqrt(std);
    
    return std;
}

int main(int argc,char** argv)
{
    ifstream in_file;
    in_file.open(argv[1]);
    string input;

    student* student_ptr=new student[1];
    int l_student=0;
    while(getline(in_file,input))
    {
        l_student+=1;
        istringstream iss;
        iss.str(input);
        string id,stu_name;
        int n;
        iss>>id>>stu_name>>n;
        //cout<<n<<endl;
        int* score_list=new int[n];
        scoreList(score_list,iss);
        
        double ave=top_ten_ave(score_list,n);
        
        cout<<id<<" "<<stu_name<<" ";
        for(int i=0;i<n;i++)
        {
            cout<<score_list[i]<<" ";
        }
        cout<<ave<<endl;

        student_ptr=studenList(id,stu_name,score_list,n,ave,student_ptr,l_student-1);
        iss.str("");
    }
    //cout<<l_student<<endl;
    cout<<stdev(student_ptr,l_student)<<endl;
    //cout<<l_student<<endl;
    in_file.close();
    return 0;
}

void scoreList(int* list,istringstream &iss)
{
    int score;
    int i=0;
    while(iss>>score)
    {
        //cout<<score<<" ";
        list[i]=score;
        i++;
    }
    //cout<<endl;
}

student* studenList(string id,string stu_name,int* score_list,int n,double ave,student* student_ptr,int l)
{
    student element={id,stu_name,score_list,n,ave};
    student* new_ptr=new student[l+1];
    
    for(int i=0;i<l;i++)
    {
        new_ptr[i]=student_ptr[i];
    }
    new_ptr[l]=element;
    delete [] student_ptr;
    student_ptr=new_ptr;

    return student_ptr;
}
