#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

string domain_name(istringstream &iss)
{
    string val;
    iss.ignore(200,'/');
    iss.ignore(200,'/');
    getline(iss,val,'/');
    return val;
}
string method(string input)
{
    int idx=input.find('?')-1;
    int head=idx;
    while(input[head]!='/')
    {
        head--;
    }

    head++;
    int l=idx-head+1;
    string val=input.substr(head,l);
    return val;
}

int main(int argc,char *argv[])
{
    ifstream in_file;
    ofstream out_file;
    in_file.open(argv[1]);
    out_file.open(argv[2]);

    out_file<<"====="<<endl;
    //cout<<"====="<<endl;
    
    string input;
    while(getline(in_file,input))
    {
        istringstream iss;
        iss.str(input);
        out_file<<"Domain name: "<<domain_name(iss)<<endl;
        string m=method(input);
        out_file<<"Method: "<<m<<endl;
        //cout<<"? : "<<input.find('?');

        iss.ignore(200,'?');
        string a,b;
        while(!iss.eof())
        {
            getline(iss,a,'=');
            int f=input.length();
            getline(iss,b,'&');
            if(b.length()>0)
            {
                out_file<<a<<": "<<b<<endl;
            }
        }
        
        /*bool watch=!strcmp(m.c_str(),"watch");
        bool search= !strcmp(m.c_str(),"search");
        bool extensions=!strcmp(m.c_str(),"extensions");
        if(watch)
        {
            char a;
            int ia = input.find('=');
            a=input[ia-1];
            iss.ignore(200,'=');
            string b;
            getline(iss,b,'&');
            out_file<<a<<": "<<b<<endl;

            string l;
            getline(iss,l,'=');
            string c;
            getline(iss,c,'&');
            out_file<<l<<": "<<c<<endl;

            string i;
            getline(iss,i,'=');
            string d;
            getline(iss,d);
            out_file<<i<<": "<<d<<endl;
        }
        else if(search)
        {
            string ch;
            iss.ignore(200,'?');
            getline(iss,ch,'=');
            string a;
            getline(iss,a,'&');
            out_file<<ch<<": "<<a<<endl;


            string client;
            getline(iss,client,'=');
            string b;
            getline(iss,b,'&');
            out_file<<client<<": "<<b<<endl;
  
            string q;
            getline(iss,q,'=');
            string c;
            getline(iss,c,'&');
            out_file<<q<<": "<<c<<endl;
        }
        else if(extensions)
        {
            iss.ignore(200,'?');
            string ub;
            getline(iss,ub,'=');
            string a;
            getline(iss,a);
            out_file<<ub<<": "<<a<<endl;
        }*/

        out_file<<"====="<<endl;
    }

    in_file.close();
    out_file.close();
    return 0;
}
