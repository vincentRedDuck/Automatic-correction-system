#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;
void parse(string,string);
int main(int argc,char *argv[]){
    ofstream outfile;
    ifstream infile;
    string in,out;
    in =argv[1];
    out=argv[2];
    infile.open(in.c_str());
    outfile.open(out.c_str(),ios::out);
        int cnt=0;
    while(!infile.eof()){
        string str,test;char chr;
        getline(infile,str,'\n');//chr=infile.get();
        
        stringstream ss;
        string tr,ut,ot,ou;char ch;int pos;
        int n=str.find("/");
        str.erase (0,n+1);
        n=str.find("/");
        if(n==0)
        str.erase (0,1);
        str=str+"&*";
        ss<<str;
        getline(ss,ut,'/');/*ch=ss.get();*/
        if(ut!="&*"){
            outfile<<"====="<<endl<<"Domain name: "<<ut<<endl;
            getline(ss,ut,'?');//ch=ss.get();
            int i=ut.find("/");
            while(i!=-1){
            ut.erase (0,i+1);
            i=ut.find("/");
            }
            outfile<<"Method: "<<ut;
            chr=ss.peek();
            while (chr!='*'){
                getline(ss,ot,'=');
                getline(ss,ou,'&');
                if(ou!="")outfile<<endl<<ot<<": "<<ou;
                chr=ss.peek();
            }
            outfile<<endl;
            
        }
    }
    outfile<<"====="<<endl;
    infile.close();
    outfile.close();
    return 0;
}
