#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    ifstream in;
    in.open(argv[1]);
    ofstream out;
    out.open(argv[2]);
    string s;
    out << "=====" << endl;
    while(getline(in, s)){
        s.erase(0,s.find("//") +2);
        cout << "s:" << s << endl;
        int x = s.find('/');
        out << "Domain name: " << s.substr(0, s.find("/")) << endl;
        cout << "Domain name: " << s.substr(0, s.find("/")+1) << endl;
        s.erase(0, x+1);
        int y = s.rfind('/');
        //out << "Domain name: " << s.substr(0, x+1) << endl;
        int q = s.find('?');
        out << "Method: " << s.substr(y+1, q-y-1) << endl;
        s.erase(0, q+1);
        /*while(!in.eof()){
            int e = s.find('=');
            if(e != s.size()-1){
                out << s.substr(0, e) << ": " << s.substr(e+1, s.size()-e) << endl;
                cout << s << endl;
            }*/
        cout << "First:" << s << endl;
        while(s.find("&") != string::npos){
            string tmp = s.substr(0, s.find("&"));
            if(tmp.substr(tmp.find("=")+1) != "")
                out << tmp.substr(0,tmp.find("=")) << ": " << tmp.substr(tmp.find("=")+1) << endl;
            s.erase(0, s.find("&") + 1);
        }
        string tmp = s.substr(0, s.find("&"));
        if(tmp.substr(tmp.find("=")+1) != "")
            out << tmp.substr(0,tmp.find("=")) << ": " << tmp.substr(tmp.find("=")+1) << endl;

        out << "=====" << endl;
    }
    return 0;
}
