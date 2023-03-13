#include <bits/stdc++.h>
using namespace std;

int main(){
    bool cond1=0,cond2=0;
    string str;
    while(1){
        int upp[26]={0},low[26]={0};
        cout << "Enter message: ";
        getline(cin,str);
        if(str=="Stop")break;
        for(int k=0; str[k]!='\0'; k++){
                cond1 = isupper(str[k]);
                cond2 = islower(str[k]);
                if(cond1!=0){
                    upp[int(str[k])-65]+=1;
                    cond1=0;
                }
                if(cond2!=0){
                    low[int(str[k])-97]+=1;
                    cond2=0;
                }
        }
        for(int i=0; i<26; i++){
            if(upp[i]!=0){
                cout << char(65+i) << ": " << upp[i] << endl;
            }
        }
        for(int i=0; i<26; i++){
            if(low[i]!=0){
                cout << char(97+i) << ": " << low[i] << endl;
            }
        }
    }
return 0;
}
