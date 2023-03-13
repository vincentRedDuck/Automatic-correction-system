#include<bits/stdc++.h>
using namespace std;

struct student{string name;int score1;int score2;int score3; double aver; };

void sortbyaver(student list[],int i)
{
    for(int j=1;j<i;j++)
    {
        student temp;
        temp=list[j];
        bool z=0;
        for(int k=j-1;k>=0;k--)
        {
            if(temp.aver<list[k].aver)
            list[k+1]=list[k];
            else
           { list[k+1]=temp;z=1;break;}
        }
        if(z==0)
        list[0]=temp;
    }
}
void sortbyname(student list[],int i)
{
    for(int j=1;j<i;j++)
    {
        student temp;
        temp=list[j];
        bool z=0;
        for(int k=j-1;k>=0;k--)
        {
            if(temp.name.compare(list[k].name)<0)
            list[k+1]=list[k];
            else
           { list[k+1]=temp;z=1;break;}
        }
        if(z==0)
        list[0]=temp;
    }
}


int main(int argc, char* argv[])
{
    ifstream fin(argv[2]);
    char c[50];
    if(argc==3)
    strcpy( c,strcat(argv[2],".out"));
    else
    strcpy( c,argv[3]);
    ofstream fout(c);
    int i;
    fin>>i;
    student list[100];
    for(int j=0;j<i;j++)
    {
        fin>>list[j].name>>list[j].score1>>list[j].score2>>list[j].score3;
        list[j].aver=(list[j].score1+list[j].score2+list[j].score3)/3.0;
    }
    if(atoi(argv[1])==1)
    {
        sortbyaver(list,i);
    }
    else
    {
        sortbyname(list,i);
    }
    for(int j=0;j<i;j++)
    {
        fout<<list[j].name<<" "<<list[j].score1<<" "<<list[j].score2<<" "<<list[j].score3<<" "<<setprecision(4)<<fixed<<list[j].aver<<endl;
    }
}
