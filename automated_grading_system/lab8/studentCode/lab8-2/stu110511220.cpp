#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void func(string ,int q[]);

int main () {
    while(true) {
        cout << "Enter message: ";
        string str;
        getline(cin,str);
        string stop = "Stop";
        if(strcmp(str.c_str(),stop.c_str())==0) {
            break;
        }
        int num[52]={0};
        func(str,num);
        for(int i=0;i<52;i++) {
            if(num[i]!=0) {
                if(i<26)
                    cout << char(65+i) << ": " << num[i] << endl;
                else
                    cout << char(97+(i-26)) << ": " << num[i] << endl;
            }
        }
    }

    return 0;
}

void func(string str,int q[]) {
    int length=strlen(str.c_str());
    for(int i=0;i<52;i++) {
        if(i<26) {
            for(int j=0;j<length;j++) {
                if(str[j]==char(65+i))
                    q[i]++;
            }
        }
        else {
            for(int j=0;j<length;j++) {
                if(str[j]==char(97+(i-26)))
                    q[i]++;
            }
        }
    } 
}
