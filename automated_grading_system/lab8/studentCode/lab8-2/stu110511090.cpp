#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cout << "Enter message: ";
    getline(cin,a);
    while(a != "Stop"){
    int b[52] = {0};
    for(int i = 0; i < a.length(); i++){
        if(int(a.at(i))>64 && int(a.at(i))<91){
            b[int(a.at(i))-65]++; 
        }
        else if(int(a.at(i)) > 96 && int(a.at(i)) < 123){
            b[int(a.at(i))-71]++;
        }        
    }
    for(int i = 0; i < 52; i++){
        if (b[i]>0&& i<26){
            cout << char(i+65) << ": "<< b[i] << endl;
        }
        else if(b[i]>0 && i>25){
            cout << char(i+71) <<": "<< b[i] << endl;
        }
    }
    cout << "Enter message: ";
    getline(cin,a);
    }
    return 0;
}

