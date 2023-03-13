#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;

string findstr (string s) {
    ifstream code("code.txt");
    string idx, morse;
    if (s == "       ") return " ";
    if (s == "   ") return "";
    while(1) {
        code >> idx;
        code.ignore(1,' ');
        getline(code,morse);
        if (idx == s)
            return morse;
        else if (morse == s)
            return idx;
    }
    code.close();
    return s;
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    char type = *argv[3];
    string text;
    getline(fin,text);
    while (!fin.eof()) {
        if (type == 'e') {
            for(int i=0; text[i]!='\0';i++) {
                ifstream code("code.txt");
                while(1) {
                    char index;
                    string newcode;
                    if (text[i] == ' ') {
                        fout << "    ";
                        break;
                    }else {
                        code >> index;
                        code.ignore(1,' ');
                        getline(code,newcode);
                    }
                        if (index == text[i]) {
                            fout << newcode << "   ";
                            break;
                        }
                }
                code.close();
            }
        }else {
            int beg=0,end=0;
            while (text[beg]!='\0') {
                end = beg+1;
                while (text[end] != '\0' && isspace(text[end])==isspace(text[end-1])) end++;
                //cout << end << endl;
                //int abc;
                //cin >> abc;
                fout << findstr(text.substr(beg,end-beg));
                beg = end;
            }
        }
        fout << endl;
        text.empty();
        getline(fin,text);
    }
    fin.close();
    fout.close();
    return 0;
}
