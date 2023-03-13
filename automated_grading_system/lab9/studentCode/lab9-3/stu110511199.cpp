#include<iostream>
#include<fstream>
using namespace std;

struct MORSE {
    char ch;
    string cd;
};
MORSE mtb[36];
void codeWrt(ifstream &, ofstream &, int);

int main(int argc, char** argv){
    ifstream fcd("code.txt");
    for (int i=0; i<36; i++){
        fcd >> mtb[i].ch >> mtb[i].cd;
    }
    fcd.close ();
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    codeWrt(fin, fout, ((argv[3][0] =='e')?1:2));
    
    return 0;
}

string getCode(char ch) {
    if (ch=='\n') return string("\n");
    if (ch==' ') return string("        ");
    for (int i=0; i<36; i++) {
        if (ch==mtb[i].ch) {
            return string(mtb[i].cd);
        }
    }
    return string("");;
}

char getChar(string &wd) {
    for (int i=0; i<36; i++) 
        if (wd==mtb[i].cd) {
            wd.clear();
            return mtb[i].ch;
        }
    return char('\0');
}

void codeWrt(ifstream &fi, ofstream &fo, int opt) {
    char ch;
    if (opt==1) {
        while (fi.get(ch)){
            fo << getCode(ch) << ((isalnum(ch)&&isalnum(fi.peek()))? "   ":"");
        }
    } else {
        string wd, wt;
        int num =0;
        while (fi.get(ch)) {
            if (ch=='.'||ch=='-') {
                wd += ch;
                num = 0;
            } else if (ch=='\n') {
                string wt = wd;
                if (getChar(wt)!='\0')
                    fo << getChar(wd);
                fo << endl;
              } else {  //is a space
                  num ++;
                  wt = wd;
                  if ((num==3)&&(getChar(wt)!='\0')){
                      fo << getChar(wd);
                  }
                  else if (num==7) fo << ' ';
                  //fo << ((num==3)? getChar(wd):((num==7)?" ":""));
                }
        }
    }
}
