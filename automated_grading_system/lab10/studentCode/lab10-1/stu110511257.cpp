#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main (int argc, char *argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    stringstream ss;
    
    string web;
    int len = web.length();
    string line, name, gar;
    while (getline(fin, web)) {
        fout << "=====\n";
        
        ss << web;
//        ss.seekg(8);
        char ch;
        while (ss.get(ch)) {
            if (ch == '/') {
                ss.get(ch);
                break;
            }
        }
//        int found1 = web.find_last_of('/');

//        line = web.substr(8, found1-8);
        getline(ss, line, '/');
        fout << "Domain name: " << line << endl;

//        line = web.substr(found1, found2-found1);
        while (getline(ss, line, '/'));
        ss.str();
        ss.clear();
        ss.str(line);
        getline(ss, line, '?');
        fout << "Method: " << line << endl;

        while (getline(ss, line, '&')) {
            int ff = line.find('=');
            name = line.substr(0, ff);
            line = line.substr(ff + 1);
            //ch = ss.peek();
            if (isalnum(line[0])) {
                fout << name << ": " << line << endl;
            }
        }

        ss.str("");
        ss.clear();
    }

    fout << "=====\n";

    return 0;
}
