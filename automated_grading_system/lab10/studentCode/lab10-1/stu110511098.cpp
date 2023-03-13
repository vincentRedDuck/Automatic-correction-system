#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;
int main(int argc,char *argv[]){
    string line;
    ifstream in_file(argv[1]);
    ofstream out_file(argv[2]);
    while(getline(in_file,line)){

        istringstream iss;
        iss.str(line);
        
        out_file<<"=====\n";
        out_file<<"Domain name: "<<line.substr(line.find("//")+2, (line.find("/",8) - line.find("//") - 2))<<"\n";
        out_file<<"Method: "<<line.substr( line.find_last_of('/') + 1  ,( line.find('?') - line.find_last_of('/'))-1 )<<"\n";
        int i=1;
        for(int n=0;n<line.length();n++){
            if(line[n]=='&'){
                i++;
            }
        }
        int pos1=line.find('?');
        int pos2=line.find('=');
        int pos3=line.find('&');
        string a;string b;string c;
        for(int j=0;j<i;j++){
            a = line.substr(pos1+1,pos2-pos1-1);
            b = line.substr(pos2+1,pos3-pos2-1);
            c = line.substr(pos1+1,pos3-pos1-1);
            
            pos1 = pos3;
            pos2 = line.find('=',pos2+1);
            pos3 = line.find('&',pos3+1);
            
            if(c.find('=') == c.length()-1){
                continue;
            }
            else{
                out_file<<a<<": "<<b<<"\n";
            }
        }
        out_file<<line.erase(0,line.find('=',pos2-1));
        line.empty();
    }
        out_file<<"=====\n";
    return 0;
}

