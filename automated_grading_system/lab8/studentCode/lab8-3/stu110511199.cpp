#include <iostream>
#include<cstring>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX=100;
void parsePrt(string, int );

int main () {
    string sentence;
    while (1) {
        cout << "Enter the sentence: " ;
        getline(cin, sentence);
        if(sentence == "Stop the program") break;
        parsePrt(sentence,0);
        cout << endl;
    }
    return 0;
}

void parsePrt(string line, int beg) {
    while (beg<line.size() && !isalpha(line[beg])) beg++;
    if (beg >=line.size()) return;
    int end =beg;
    while (end<line.size() && isalpha(line[end])) end++;
    parsePrt(line, end);
    cout << line.substr(beg, end-beg) << " " ;
}
/*void init(char[]);
void head(char[], int&, int&);
void tail(char[], int&, int&);
*
int main() {
    char str[MAX];
    init(str);
    string vstr;
    string ans;
    cout << "Enter the sentence: " ;
    getline(cin, vstr);
    strcpy(str, vstr.c_str());
    while(strcmp(str.c_str,"Stop the program")) {
        int i=0, j=0;
        while (i < MAX && j < MAX){
            head(str, i, j);
            ans = vstr.substr(i,j-i) +" " + ans;
            tail(str, j, i);
        } 
        cout << ans << endl;
        cout << "Enter the sentence: " ;
        init(str);
        getline(cin, vstr);
        strcpy(str, vstr.c_str());
     }
 return 0;
}

void head(char ch[], int& x, int& y){
    for (int i=x; i<MAX; i++) {
        if (!isalpha(ch[i])) {
            y=i+1;
            break;
        }
    }
}
void tail(char ch[], int& y, int& x){
    for (int i=y; i<MAX; i++) {
        if (isalpha(ch[i])){
            x=i+1;
            break;
        }
    }
}
void init(char ch[]) {
    for(int i=0; i<MAX; i++)
        ch[i]='\0';
}*/
