#include<iostream>
#include<string>
using namespace std;
int main(){

string x;
cout << "Enter the sentence: ";
getline(cin,x);
string fin;
int start=0;
int end=0;
int temp=0;

while(x!="Stop the program"){
    for(int i=0;i<x.length();i++){
        end = temp;
        if(((x[i]>64&&x[i]<91)||(x[i]>96&&x[i]<123))
        &&(x[i-1]<64||(x[i-1]>91&&x[i-1]<96)||x[i-1]>123)&&(i>0)){
            start=i;
        }
        if(((x[i]>64&&x[i]<91)||(x[i]>96&&x[i]<123))
        &&(x[i+1]<64||(x[i+1]>91&&x[i+1]<96)||x[i+1]>123)){
            end=i;
        }
        if(end!=temp){
            fin =  x.substr(start,end-start+1) + " " + fin;
        }
    }
    start =0;
    end = 0;
    temp = 0;
    cout << fin << endl;
    fin = "";
    cout << "Enter the sentence: ";
    getline(cin,x);
}

return 0;
}
