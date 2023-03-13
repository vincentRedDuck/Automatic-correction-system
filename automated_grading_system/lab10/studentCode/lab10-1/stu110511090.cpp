#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char **argv){
    ifstream infile;
    infile.open(argv[1]);
    ofstream outfile;
    outfile.open(argv[2]);
    outfile << "=====" << endl;
    string line;
    while(getline(infile,line)){
        string s1;
        line.erase(0,line.find("//")+2);
        int pos = line.find("/");
        s1 = line.substr(0,pos);
        outfile << "Domain name: " << s1 << endl;
        pos = line.find("?");
        for(int i = 0; i < pos; i++){
            if(line[pos-i]=='/'){
                s1 = line.substr(pos-i+1,i-1);
                outfile << "Method: " << s1 << endl;
                break;
            }
        }
        s1 = line.erase(0,pos+1);
        string s2;
        while(s1.find('&') != string::npos){
            s2 = s1;
            cout <<"s1: " << s1 <<endl;    
            s1.erase(0, s1.find('&')+1);
            s2.erase(s2.find('&'));
            string tmp1 = s2, tmp2 = s2;
            tmp1.erase(tmp1.find('='));
            tmp2.erase(0, tmp2.find('=')+1);
            cout <<"s2: " << s2 <<endl; 
            cout << "tmp1: " << tmp1 << endl;
            cout << "tmp2: " << tmp2 << endl;
            if(tmp2 != ""){
                outfile << tmp1 << ": " << tmp2 <<endl;    
            } 
        }
        string tmp1 = s1, tmp2 = s1;
        tmp1.erase(tmp1.find('='));
        tmp2.erase(0, tmp2.find('=')+1);           
        if(tmp2 != ""){
            outfile << tmp1 << ": " << tmp2 <<endl;    
        } 
        outfile << "=====" << endl;
    }
    return 0;
}
