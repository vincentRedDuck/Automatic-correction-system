#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<cstring>
using namespace std;

struct stu
{
    string name;
    int s1;
    int s2;
    int s3;
    double ave;
};

void cmp_prt(stu student[],int num)
{
    int l=num;
    for(int i=0;i<l;i++)
    {
        cout<<student[i].name.c_str();
        if(i!=l-1)
        {
            cout<<"--";
        }
        else
        {
            cout<<endl;
        }
    }
}

void sort(stu student[],int num,string mode)
{
    for(int j=1;j<num;j++)
    {
            stu key=student[j];
            int i=j-1;
            if(mode=="1")//ave
            {
                double val=key.ave;
                while((i>=0)&&(student[i].ave>val))
                {
                    student[i+1]=student[i];
                    i--;
                }
                student[i+1]=key;
            }
            else if(mode=="2")//name
            {
                string n=key.name;
                while((i>=0)&&(strcmp(student[i].name.c_str(),n.c_str())>0))
                {
                    student[i+1]=student[i];
                    i--;
                }
                student[i+1]=key;
            }
        
    }
}


void prtStu(stu student[],int num)
{
    for(int i=0;i<num;i++)
    {
        stu item=student[i];
        cout<<fixed<<showpoint<<setprecision(4);
        cout<<item.name<<" "<<item.s1<<" "<<item.s2<<" "<<item.s3<<" "<<item.ave<<endl;
        //cout<<item.name<<" "<<item.s1<<" "<<item.s2<<" "<<item.s3<<endl;
    }
}

int main(int argc,char* argv[])
{
    ifstream in_file;
    ofstream out_file;
    
    if(argc==3)
    {
        string in_name;
        in_name=argv[2];
        string out_name=in_name+".out";
        in_file.open(in_name.c_str());
        out_file.open(out_name.c_str());
    }
    else if(argc==4)
    {
        in_file.open(argv[2]);
        out_file.open(argv[3]);
    }
        
    if(in_file.fail())
    {
        cout<<"in error"<<endl;
        exit(1);
    }

    string str;
    getline(in_file,str);
    int num=atoi(str.c_str());
    stu student[num+1];    

    for(int i=0;i<num;i++)
    {
        string data;
        getline(in_file,data,' ');
        if(data[0]=='\n')
        {
            data.erase(0,1);
        }
        int a1,a2,a3;
        in_file>>a1>>a2>>a3;
        double val=(a1+a2+a3)/3.0;
        stu item={data,a1,a2,a3,val};        
        student[i]=item;
    }

    string mode=argv[1];

    sort(student,num,mode);
    
    for(int i=0;i<num;i++)
    {
        stu item=student[i];
        out_file<<fixed<<showpoint<<setprecision(4);
        out_file<<item.name<<" "<<item.s1<<" "<<item.s2<<" "<<item.s3<<" "<<item.ave<<endl;
        //cout<<item.name<<" "<<item.s1<<" "<<item.s2<<" "<<item.s3<<endl;
    }

    //cmp_prt(student,num);
    prtStu(student,num);
    //cmp_prt(student,num);

    in_file.close();
    out_file.close();
    return 0;
}
