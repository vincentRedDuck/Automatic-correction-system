#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

int main(int argc,char* argv[])
{
    ifstream in_file;
    ofstream out_file;
    double a=0;
    string in,out;
    in_file.open(argv[1]);
    out_file.open(argv[2]);
    if(in_file.fail())
    {
        cout<<"in Does not exist"<<endl;
        exit(1);
    }
    if(out_file.fail())
    {
        cout<<"out does not exist"<<endl;
        exit(1);
    }

    int count=0;
    while(!in_file.eof())
    {
        string w;
        getline(in_file,w);
        int l=w.length();
        int id = w.find(':');
        count+=1;
        if(id!=l-1)
        {
            string num=w.substr(id+1,l-id-1);
            a+=atof(num.c_str());              
        }
    }
    
    count-=1;

    if(count!=0)
    {
        a/=count;
    }
    //cout<<a<<endl<<count<<endl;
    out_file<<"The average is: "<<fixed<<showpoint<<setprecision(4)<<a;

    in_file.close();
    out_file.close();

    return 0;
}

