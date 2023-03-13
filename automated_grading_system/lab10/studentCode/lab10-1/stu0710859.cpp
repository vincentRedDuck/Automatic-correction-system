#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    ifstream file1;
    ofstream file2;
    int c, d;
    string rfile = argv[1], wfile = argv[2], str, temp, temp1;
    file1.open(rfile);
    file2.open(wfile, ios::out);
    file2 << "=====" << endl;
    while(getline(file1,str)){
        c = str.find('/');
        str.erase(0,c+2);
        c = str.find('/');
        temp = str.substr(0,c);
        file2 << "Domain name: " << temp << endl;
        str.erase(0,c+1);
        c = str.find('/');
        while(c > 0){
            c = str.find('/');
            str.erase(0,c+1);
        }
        c = str.find('?');
        temp = str.substr(0,c);
        file2 << "Method: " << temp << endl;
        str.erase(0,c+1);
        c = str.find('&');
        while(c > 0){
            temp = str.substr(0,c);
            d = str.find('=');
            if(temp.length()-1 > d){
                temp1 = temp.substr(0,d);
                temp.erase(0,d+1);
                file2 << temp1 << ": " << temp << endl;
            }
            str.erase(0,c+1);
            c = str.find('&');
        }
        d = str.find('=');
        if(str.length()-1 > d){
            temp1 = str.substr(0,d);
            str.erase(0,d+1);
            file2 << temp1 << ": " << str << endl;
        }
        file2 << "=====" << endl;
    }
    return 0;
}
