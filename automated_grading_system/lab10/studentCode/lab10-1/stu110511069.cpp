#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

int main(int argc,char **argv){
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    string line;
    char c;
    fout<<"====="<<endl; 
    while(getline(fin,line)){
        
        stringstream ss(line);
        string temp,temp2;
        getline(ss,temp,'/');

        getline(ss,temp,'/');


        getline(ss,temp,'?');
        fout<<"Domain name: ";

        //www.
        int len = 0;
        int first = 0;
        for(int i = 0 ;i<temp.length();i++){
            if(temp[i]=='/'){
                len = i;
                if(first ==0){
                    first = i;
                }
            }
        }
        stringstream ssdo(temp);
        for(int i =0;i<len;i++){
            ssdo.get(c);
           if(i<first){
               fout<<c;
            }
        }
        fout<<endl;
        ssdo.get(c);
        string method;
        ssdo>> method;
        fout<<"Method: "<<method<<endl;
        //search
        
        while(ss.str().length()>0){
            if(!getline(ss,temp,'='))break;

            if(!getline(ss,temp2,'&'))continue;
            if(temp2=="") continue;
            fout<<temp<<": ";
            fout<<temp2<<endl;
        
        }
        fout<<"====="<<endl;
        //fs
       
    }
    return 0;
}
