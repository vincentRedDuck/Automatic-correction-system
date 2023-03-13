#include<iostream>
#include<cstring>
#include<fstream>
#include<cctype>
using namespace std;

struct code {
    char alpha;
    string CODE;
};

void decode(string);
void encode(string);

int main (int argc,char* argv[]) {
    ifstream inFile("code.txt");
    code morse[36];
    for(int i=0;i<36;i++) {
        inFile >> morse[i].alpha;
        inFile >> morse[i].CODE;
    }
    ifstream fin(argv[1]);
    ofstream outFile(argv[2]);
    string aa = argv[3];
    if(aa=="d") {
        string str;
        while(getline(fin,str)) {
            for(int i=0,j=0;i<str.length();) {
                if(i==str.length()-1) {
                    string line;
                    line = str[i];
                    for(int i=0;i<36;i++) {
                        if(morse[i].CODE == line) {
                            outFile << morse[i].alpha;
                            break;
                        }
                    }
                }
                while(str[i]!=' '&&i!=str.length()-1) {
                    j++;
                    if(j==str.length()-1) {
                        string line = str.substr(i,j-i+1);
                        for(int i=0;i<36;i++) {
                            if(morse[i].CODE == line) {
                                outFile << morse[i].alpha;
                                break;
                            }
                        }
                    i=j;
                    }
                   if(str[j]==' ') {
                    string line = str.substr(i,j-i);
                    for(int i=0;i<36;i++) {
                        if(morse[i].CODE == line) {
                            outFile << morse[i].alpha;
                            break;
                        }
                    }
                i=j;
                } 
                }
                if(i==str.length()-1) {
                    outFile << endl;
                    break;
                }
                while(str[i]==' ') {
                    j++;
                    if(str[j]!=' '&&(j-i)==7) {
                        outFile << " ";
                        i=j;
                    }
                    else if(str[j]!=' '&&(j-i)==3)
                        i=j;
                }
            }
        }
    }
    else if(aa == "e") {
        string str;
        while(getline(fin,str)) {
            for(int i=0;i<str.length();i++) {
                if(isalpha(str[i])) {
                    int num = int(str[i])-65;
                    outFile << morse[num].CODE;
                }
                else if(isdigit(str[i])) {
                    int num = (((int(str[i])-48)>0) ? int(str[i])-48+25 : 35);
                    outFile << morse[num].CODE;
                }
                if (str[i]==' ') {
                    outFile << "       ";
                }
                else if (i==str.length()-1)
                    outFile << endl;
                else if (str[i+1]!=' ') {
                    outFile << "   ";
                }
            }
        }
    }
    
    return 0;
}
