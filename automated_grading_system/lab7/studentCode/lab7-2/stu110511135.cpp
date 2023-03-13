#include<iostream>
using namespace std;

int main(){
    cout << "1: encoder 2: decoder 3: quit: ";
    int a;
    cin >> a;
    int len;
    char code[100];
while(a!=3){
if(a>3 || a<1){
    cout << "invalid input";
    cout << "\n\n";
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> a;
    continue;
}
cout << "Please enter sentences length: ";
cin >> len;
if(a==1){
    for(int i=0; i<len; i++){
        cin >> code[i];
    }
    for(int i=0; i<len; i+=2){
        cout << code[i];
    }
    for(int i=1; i<len; i+=2){
        cout << code[i];
    }
}
if(a==2){
    for(int i=0; i<len; i++){
        cin >> code[i];
    }
    for(int i=0; i<len/2; i++){
        cout << code[i];
        cout << code[i+len/2];
    }
    if(len%2==1){
        cout << code[len];
    }
}
cout << "\n\n";
cout << "1: encoder 2: decoder 3: quit: ";
cin >> a;
}
return 0;
}
