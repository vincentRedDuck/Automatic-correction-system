#include <bits/stdc++.h>
using namespace std;

struct MORSE{
    char ch;
    string cd;

};
MORSE mtb[36];
void codecWrt(ifstream&,ofstream &,int);

int main(int agrc, char *argv[]){
    ifstream fin("code.txt");
    for(int i=0;i<36;i++)
    {
        fin>>mtb[i].ch>>mtb[i].cd;
    }
    fin.close();
    ifstream fi(argv[1]);
    ofstream fout(argv[2]);
    codecWrt(fi,fout,((*argv[3]=='e')?1:2));
    return 0;
}
string getCode(char ch)
{
    if (ch=='\n') return string("\n");
    if (ch==' ') return string("       ");
    for(int i=0;i<36;i++)
    {
        if(ch==mtb[i].ch)
        {
            return string(mtb[i].cd);
        }
    }

    return string("");
}
char getChar(string &wd){
    for(int i=0;i<36;i++)
        if(wd==mtb[i].cd){
            wd.clear();
            return mtb[i].ch;
        }
        return char('\n');
}
void codecWrt(ifstream &fin, ofstream &fout,int opt)
{
    char ch;
    if(opt==1){
        while(fin.get(ch))
        {
            fout<<getCode(ch)<<((isalnum(ch) && isalnum(fin.peek()))?"   ":"");
        }
    }
    else{
        string wd;
        int num=0;
        while(fin.get(ch))
        {
            if(ch=='.' || ch=='-')
            {
                wd+=ch;
                num=0;
            }
            else if(ch=='\n')
            {
                fout<<getChar(wd)<<endl;
            }
            else
            {
                num++;
                if(num==3)fout<<getChar(wd);
                else if(num==7)fout<<" ";
            }
        }
    }
}
/*#include <bits/stdc++.h>
using namespace std;

struct MORSE{
    char ch;
    string cd;

};
MORSE mtb[36];
void codecWrt(ifstream&,ofstream &,int);

int main(int agrc, char *argv[]){
    ifstream fin("code.txt");
    for(int i=0;i<36;i++)
    {
        fin>>mtb[i].ch>>mtb[i].cd;
    }
    fin.close();
    ifstream fi(argv[1]);
    ofstream fout(argv[2]);
    codecWrt(fi,fout,((argv[3][0]=='e')?1:2));
    return 0;
}
string getCode(char ch)
{
    if (ch=='\n') return string("\n");
    if (ch==' ') return string("       ");
    for(int i=0;i<36;i++)
    {
        if(ch==mtb[i].ch)
        {
            return string(mtb[i].cd);
        }
    }

    return string("");
}
char getChar(string &wd){
    for(int i=0;i<36;i++)
        if(wd==mtb[i].cd){
            wd.clear();
            return mtb[i].ch;
        }
        return char('\n');
}
void codecWrt(ifstream &fin, ofstream &fout,int opt)
{
    char ch;
    if(opt==1){
        while(fin.get(ch)){
            fout<<getCode(ch)<<((isalnum(ch) && isalnum(fin.peek()))?"   ":"");
        }
    }
    else{
        string wd;
        int num=0;
        while(fin.get(ch))
        {
            if(ch=='.' || ch=='-')
            {
                wd+=ch;
                num=0;
            }
            else if(ch=='\n')
            {
                fout<<getChar(wd)<<endl;
            }
            else
            {
                num++;
               if(num==3)
                   fout<<getChar(wd);
                 if  (num==7)
                     fout<<" ";
            }
        }
    }
}
*/



