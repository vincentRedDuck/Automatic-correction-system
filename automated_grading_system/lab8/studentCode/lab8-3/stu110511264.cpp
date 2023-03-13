#include<bits/stdc++.h>
using namespace std;
int main(){
while(1){
    int n=0;
    string x,y[100];
    cout<<"Enter the sentence: ";
    getline(cin, x);
    if(x=="Stop the program"){
        return 0;
    }
    for(int i=0;i<100;i++){
        y[i]="\0";
    }
    for(int i=0;i<x.length();i++){
        if(isalpha(x[i])){
            y[n]=y[n]+x[i];
        }
        else{
            n++;
        }
    }
    for(int i=99;i>=0;i--){
        if(y[i]!="\0"){
            cout<<y[i]<<" ";
        }
    }
    cout<<"\n";
}
    return 0;
}
