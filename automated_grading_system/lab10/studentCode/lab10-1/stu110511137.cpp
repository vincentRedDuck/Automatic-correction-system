#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin.ignore(8,'/');
    fin.ignore(2,'/');
    stringstream ss;
    string line;
    getline(fin,line);
    ss.str(line);
    while(!fin.eof()) {
        string s;
        getline(ss,s,'/');
        fout << "=====" << endl;
        fout << "Domain name: " << s << endl;
        getline(ss,s,'?');
        //cout << s << endl;
        int i=0;
        for (i=s.size()-1; i>0; i--) {
            if(s[i]=='/') {
                i++;
                break;
            }
        }
        //cout << s.substr(i,s.size()-i) << endl;
        fout << "Method: " << s.substr(i,s.size()-i) << endl;
        
        //getline(fin,line);
        //ss.str(line);
        string infor1,infor2;
        getline(ss,infor1,'=');
        getline(ss,infor2,'&');
        while(!ss.eof()/*getline(ss,infor1,'='),getline(ss,infor1,'&')*/) {
            if(infor2 != "") {
                fout << infor1 << ": " << infor2 << endl;
            }
            getline(ss,infor1,'=');
            getline(ss,infor2,'&');
        }
        if(infor2 != "") {
            fout << infor1 << ": " << infor2 << endl;
        }
        ss << "";
        ss.clear();
        fin.ignore(8,'/');
        fin.ignore(2,'/');
        getline(fin,line);
        ss.str(line);
    }
    fout << "=====" << endl;
    fin.close();
    fout.close();
    return 0;
}
