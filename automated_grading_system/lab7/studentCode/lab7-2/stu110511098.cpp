#include<iostream>
using namespace std;

void encoder(char obj[],int l){
    for(int i=0;i<l;i+=2){
        cout<<obj[i];
    }
    for(int i=1;i<l;i+=2){
        cout<<obj[i];
    }
    cout<<"\n";
}
void decoder(char obj[],int l){
    for(int i=0;i<l/2;i++){
        cout<<obj[i]<<obj[i+l/2];
    }
    cout<<"\n";
}

int main(){
    int n,len;
    char sen[100];
    cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>n;
    while(n!=3){
        if(n!=1&&n!=2){
            cout<<"Invalid input\n\n";
            continue;
        }
        cout<<"Please enter sentences length: ";
        cin>>len;
        for(int i=0;i<len;i++){
            cin>>sen[i];
        }
        if(n==1){
            encoder(sen,len);
        }
        if(n==2){
            decoder(sen,len);
        }
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>n;
    }
    return 0;
}
