#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(int argc,char **argv){

    stringstream ss;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    string line;
    //ss.str(line);
    string x;    
    while(getline(fin,line)){
        fout << "=====" << endl;
        ss.str(line);
        ss.ignore(100,'/');
        ss.ignore(100,'/');
        getline(ss,x,'/');
        fout << "Domain name: " << x << endl;
        getline(ss,x,'?');
        while(x.find('/') != -1){
            x.erase(0,x.find('/')+1);
        }
        fout << "Method: " << x << endl;
        string type;
        string category;
        for(int i=0;i<line.length();i++){
            if(line[i]=='&'){
                getline(ss,type,'=');
                getline(ss,category,'&');
                if(category!="")
                fout << type << ": " << category << endl;
            }
            if(i==line.length()-1){
                getline(ss,type,'=');
                getline(ss,category);
                if(category!="")
                    fout << type << ": " << category << endl;
            }
        }x="";
        line = "";
        ss.clear();
    }
    fout << "=====" << endl;
    fin.close();
    fout.close();
    return 0;
}
