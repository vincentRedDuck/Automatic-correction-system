#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    ofstream fot(argv[2]);

    string l1,l2,tok;
    while (getline(fin,l1)) {
        stringstream ss(l1);
        //process Domain name
        getline(ss,l1,'/'); getline(ss,l1,'/'); getline(ss,tok,'/');
        fot << "=====\nDomain name: " << tok << endl;
        getline(ss,l1,'?'); getline(ss,l2);
        //process method
        ss.clear(); ss.str(l1);
        while (getline(ss,tok,'/')) ;
        fot << "Method: " << tok << endl;
        //process attributes
        ss.clear(); ss.str(l2);
        while (getline(ss,tok,'&')) {
            stringstream tt(tok);
            getline(tt,l1,'='); getline(tt,l2);
            if (l2!="") fot << l1 << ": " << l2 << endl;
        }
    }
    fot << "=====" << endl;
    return 0;
}
