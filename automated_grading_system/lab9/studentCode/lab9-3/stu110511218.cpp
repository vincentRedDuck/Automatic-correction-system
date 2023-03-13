#include<bits/stdc++.h>
using namespace std;

string chartable[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string numtable[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};


int main(int argc,char *argv[])
{
    ifstream fin(argv[1]);
ofstream fout(argv[2]);

    if(!strcmp(argv[3],"e"))
    {
    char in1;
    while(!fin.eof())
    {
        fin.get(in1);
        if(in1=='\n')
        fout<<'\n';
        else if(in1==' ')
        fout<<"    ";
        else if(in1>='A'&&in1<='Z')
        {
        int i=in1-'A';
        fout<<chartable[i]<<"   ";
        }
        else
        {
        int i=in1-'0';
        fout<<numtable[i]<<"   ";
        }
    }
    }
    else
    {
     string in;
    char c;
    int count;
    while(!fin.eof())
    {
        if(fin.peek()==' ')
        {
            count=0;
            do
            {fin.get(c);count++;}
            while(fin.peek()==' ');
            if(count==7)
            fout<<' ';
        }
        else if(fin.peek()=='\n')
        {fin.ignore(1,'\n');fout<<'\n';}
        else
        {
            fin>>in;
            if(in.length()<5)
            {
                for(int k=0;k<26;k++)
                {
                if(in==chartable[k])
                {fout<<char('A'+k);break;}
                }
            
            }
            else
            {
             for(int k=0;k<10;k++)
               {
               if(in==numtable[k])
                {fout<<char('0'+k);break;}
                }
            }
            in.clear();
        }
        }
    }
}


