#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in" << endl;
    ofstream out_file;
    out_file.open(argv[2]);
    if(out_file.fail())cout << "ERROR out" << endl;
    string str, temp, name;
    istringstream iss;

    out_file << "=====" << endl;
    while(getline(in_file, str)){
        str.erase(0, str.find('/')+2);
        temp = str.substr(0, str.find('/'));
        str.erase(0, str.find('/')+1);
        out_file << "Domain name: " << temp << endl;
        
        while(str.find('/')<str.find('?'))str.erase(0, str.find('/')+1);
        temp = str.substr(0, str.find('?')); 
        str.erase(0, str.find('?')+1);
        out_file << "Method: " << temp << endl;
        
        iss.str(str);
        while(getline(iss, name, '=')){
            getline(iss, temp, '&');
            if(temp.compare("\0"))out_file << name << ": " << temp << endl;
        }

        iss.clear();
        out_file << "=====" << endl;
    }
    in_file.close();
    out_file.close();
    return 0;
}
