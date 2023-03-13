#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

void alpha(string,int,bool cond[]);

int main () {
    while(1) {
        cout << "Enter the sentence: ";
        string str;
        getline(cin,str);
        if(str=="Stop the program")
            break;
        int length=strlen(str.c_str());
        bool cond[length];
        alpha(str,length,cond);
        for(int i=length-1,j=0;i>=0;i--) {
            while(cond[i]==true) {
                i--;
                j++;
            }
            if(cond[i]==false&&cond[i+1]==true) {
                cout << str.substr(i+1,j) << " ";
                j=0;
            }
        }
        cout << endl;
        }
    

    return 0;
}

void alpha(string str,int length,bool cond[]) {
    for(int i=0;i<length;i++) {
        cond[i] = isalpha(str[i]);
    }
}
