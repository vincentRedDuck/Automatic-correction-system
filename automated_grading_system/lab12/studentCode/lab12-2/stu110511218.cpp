#include<bits/stdc++.h>
using namespace std;

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average;
};

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1]);
    string str;
    int stucount=1;
    student* stuarr=new student[stucount];
    
    while(getline(fin,str))
    {   
        
        
        student* temp=new student[stucount];
        for(int i=0;i<stucount-1;i++)
        {
            temp[i]=stuarr[i];
        }
        delete [] stuarr;
        stuarr=temp;
        student* who=&(stuarr[stucount-1]);
        stringstream ss(str);
        ss>>who->ID;
        ss>>who->name;
        ss>>who->num_score;
        who->score=new int[who->num_score];
        for(int i=0;i<who->num_score;i++)
        {
            ss>>who->score[i];
        }
        
        int count=0;
        double sum=0;
        bool b=0;
        for(int i=10;i>=0;i--)
        {
            for(int j=0;j<who->num_score;j++)
            {
                if(who->score[j]==i)
                {
                    sum+=who->score[j];
                    count++;
                    if(count==10)
                    {
                        b=1;
                        break;
                    }
                }
            }
            if(b)
            {
                break;
            }
        }
        who->average=sum/count;
        cout<<who->ID<<' '<<who->name<<' '<<flush;
        for(int i=0;i<who->num_score;i++)
        {
            cout<<who->score[i]<<' ';
        }
        cout<<who->average<<endl;
        stucount++;
    }
    stucount--;
    double aversum=0;
    double u,sigma;
    for(int i=0;i<stucount;i++)
    {
        aversum+=stuarr[i].average;
    }
    u=aversum/stucount;
    aversum=0;
    for(int i=0;i<stucount;i++)
    {
        aversum+=pow((stuarr[i].average-u),2);
    }
    sigma=sqrt(aversum/stucount);
    cout<<sigma<<endl;
}
