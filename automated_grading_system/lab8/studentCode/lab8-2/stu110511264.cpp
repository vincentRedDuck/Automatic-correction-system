#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        string x;
        cout<<"Enter message: ";
        getline(cin, x);
        if(x=="Stop"){
            break;
        }
        int U[26]={0},L[26]={0};
        for(int i=0;i<sizeof(x)-1;i++){
            if(isalpha(x[i])){
                if(int(x[i])>64&&int(x[i])<91){
                    U[x[i]-65]=U[x[i]-65]+1;
                }
                if(int(x[i])>96&&int(x[i])<123){
                    L[x[i]-97]=L[x[i]-97]+1;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(U[i]>0){
                cout<<char(i+65)<<": "<<U[i]<<"\n";
            }
        }
       for(int i=0;i<26;i++){
            if(L[i]>0){
                cout<<char(i+97)<<": "<<L[i]<<"\n";
            }
        }
    }
    return 0;
}
