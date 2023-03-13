#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char **argv) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    string line; 
    fout << "=====" << endl;
    while(getline(fin, line)){ 
        stringstream ss;
        stringstream ss2;
        ss << line;
        getline(ss, line, '/');  
        getline(ss, line, '/');
        getline(ss, line, '/');

        fout << "Domain name: " << line << endl;
        while(getline(ss, line, '/')) {
        }
        ss2<<line;
        getline(ss2, line, '?');
        fout << "Method: " << line << endl;
        getline(ss2, line);
        ss2 << "" ; ss2.clear();
        ss2 << line;
        string line2;
        while (true) {
            if(!getline(ss2, line, '='))break;
            if(!getline(ss2, line2, '&')) break;
            if(line2!=""){
                fout << line << ": ";
                fout<< line2 <<endl;
            }
        }
        fout << "=====" << endl;
    }
    return 0;
}
