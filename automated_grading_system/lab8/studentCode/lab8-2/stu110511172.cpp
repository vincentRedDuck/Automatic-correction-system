#include<iostream>
#include<string>
using namespace std;

void sort(string &x){
    for(int j=0;j<x.length();j++){
    for(int i=0;i<x.length();i++){
    if(i<x.length()-1){
        if(x[i]>x[i+1]){
            char temp = x[i];
            x[i] = x[i+1];
            x[i+1] = temp;
        }}
    }}
}

void printmes(string x){
    sort(x);
    int len = x.length();
    for(int i=0;len>=1;){
        char key;
        int t=1;
        key = x.at(0);
        //cout << "x =" << x <<endl;
        //cout <<"key = " << key<< endl;
        if((key>64&&key<91)||(key>96&&key<123)){
        cout << key;}
        x.erase(0,1);
        len--;
        for(int j=0;j<len;j++){
            if(x.at(j)==key){
                t++;
                x.erase(j,1);
                len--;
            }
        }    
        if((key>64&&key<91)||(key>96&&key<123)){
        cout << ": " << t << endl;}
    }
}

int main(){

string x;
string key = "Stop";
while(1){

    cout << "Enter message: ";
    getline(cin,x);
    if(x==key){
        break;
    } 
    else{
        printmes(x);
    }
}

return 0;
}
