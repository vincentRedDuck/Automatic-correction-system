#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;
int main (int argc,char **argv) {
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    string str;
    while(getline(inFile,str)) {
        int k=0;
        outFile << "=====" << endl;
        for(int i=0;i<str.length();i++) {
            int j=i;
            while(isalpha(str[i])&&str[i-1]=='/'&&str[i-2]=='/') {
                j++;
                if(str[j]=='/') {
                    outFile << "Domain name: " << str.substr(i,j-i) << endl;
                    i=j;
                    k=1;
                }
            }
            while(str[i]=='/'&&k==1) {
                j++;
                if(str[j]=='/') 
                    i=j;
                if(str[j]=='?') {
                    outFile << "Method: " << str.substr(i+1,j-i-1) << endl;
                    i=j;
                }
            }
            while(isalnum(str[i])&&k==1) {
                j++;
                if(str[j]=='='&&(j==str.length()-1||str[j+1]=='&')) {
                    i=j;
                    break;
                }
                if(str[j]=='='&&str[j+1]!='&') {
                    outFile << str.substr(i,j-i) << ": ";
                    i=j;
                }
                if(i==str.length()-1){
                    outFile << str[i] << endl;
                    i=j;
                    break;
                }
                if(j==str.length()-1) {
                    outFile << str.substr(i,j-i+1) << endl;
                    i=j;
                    break;
                }
                if(str[j]=='&') {
                    outFile << str.substr(i,j-i) << endl;
                    i=j;
                }
                /*if(str[j]=='='&&(str[j+1]=='&'||j==str.length()-3)) {
                    i=j;
                    break;
                }*/
              /*  if(str[j+1]=='\n') {
                    outFile << str.substr(i,j-i) << endl;
                    i=j;
                }*/
            }
        }
    }
    outFile << "=====" << endl;
    return 0;
}
