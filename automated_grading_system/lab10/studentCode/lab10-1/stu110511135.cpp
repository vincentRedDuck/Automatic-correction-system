#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char *argv[]){
    stringstream ss;
    ofstream fout(argv[2]);
    ifstream fin(argv[1]);
    string line,line2;
    bool flag = true;
    int find=0;
    char ch;
    while(getline(fin,line)){
        fout << "=====" << endl;
        ss << line;
        while(ss.get(ch)){
            if(ch=='/'){
                ss.get(ch);
                break;
            }
        }
        getline(ss,line, '/');
        fout << "Domain name: " << line << endl;
        while(getline(ss,line,'/'));
        ss.str("");
        ss.clear();
        ss.str(line);
        getline(ss,line,'?');
        /*int find = line.find_last_of('/');
        line = line.substr(find,'?');*/
        fout << "Method: " << line << endl;
        while(getline(ss,line,'=')){
            getline(ss,line2,'&');
            if(line2!=""){
                fout << line << ": ";
                fout << line2 << endl;
            }
        }
        ss.str("");
        ss.clear();   
        flag = true;
    }
    fout << "=====" << endl;
return 0;
}
