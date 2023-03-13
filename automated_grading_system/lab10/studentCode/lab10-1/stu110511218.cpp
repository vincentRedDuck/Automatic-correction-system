#include<bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    string str,domain,method,str1,str2;
    while(getline(fin,str))
    {
        for(int i=0;i<5;i++)
        fout<<'=';
        fout<<endl;
        str.erase(0,str.find('/',0)+1);str.erase(0,str.find('/',0)+1);       
        domain=str.substr(0,str.find('/',0));
        str.erase(0,str.find('/',0)+1);
        fout<<"Domain name: "<<domain<<endl;
        while(str.find('/',0)!=-1)
        {

            str.erase(0,str.find('/',0)+1);
        }
        method=str.substr(0,str.find('?',0));
        str.erase(0,str.find('?',0)+1);
        fout<<"Method: "<<method<<endl;
        while(str.find('=',0)!=-1)
        {
            str1=str.substr(0,str.find('=',0));
            str.erase(0,str.find('=',0)+1);
            if(str.find('&')!=-1)
            {str2=str.substr(0,str.find('&',0));
            str.erase(0,str.find('&',0)+1);}
            else
            {str2=str;
            str.clear();}
            if(str2!="")
            fout<<str1<<": "<<str2<<endl;
        }
    }
    for(int i=0;i<5;i++)
        fout<<'=';
        fout<<endl;
}
