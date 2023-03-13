#include<bits/stdc++.h>
using namespace std;
void f1(char sen[],int len){
    for(int i=0;i<len;i+=2){
        cout<<sen[i];
    }
    for(int i=1;i<len;i+=2){
        cout<<sen[i];
    }
    cout<<"\n\n";    
}
void f2(char sen[],int len){
    for(int i=0;i<len/2;i++){
        cout<<sen[i]<<sen[i+len/2];
    }
    cout<<"\n\n";
}
int main(){
    while(1){
        int a;
        int len;
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>a;
        if(a==3){
            return 0;
        }
        else if(a!=1&&a!=2&&a!=3){
            cout<<"invalid input"<<"\n\n";
            continue;
        }
        cout<<"Please enter sentences length: ";
        cin>>len;
        char sen[len];
        for(int i=0;i<len;i++){
            cin>>sen[i];
        }
        if(a==1){
            f1(sen,len);
        }
        else if(a==2){
            f2(sen,len);
        }
    }
    return 0;
}
