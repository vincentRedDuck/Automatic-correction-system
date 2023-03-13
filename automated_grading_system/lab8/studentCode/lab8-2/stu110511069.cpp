#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
int asc[128] = {0};

void reset(){
    for(int i =0;i<128;i++)asc[i] = 0;
}
int main(){
    string s;
    cout<<"Enter message: ";
    getline(cin,s); 
    while(s!="Stop"){
        
        for(int i =0;i<s.length();i++){
            asc[s[i]]++;
        }
        for(int i = int('A');i<=int('Z');i++){
            if(asc[i]>0) cout<< char(i)<<": "<<asc[i]<<endl;
        }
        for(int i = int('a');i<=int('z');i++){
            if(asc[i]>0) cout<< char(i)<<": "<<asc[i]<<endl;
        }
        reset();
            cout<<"Enter message: ";
        getline(cin,s);
    }    
    return 0;
}
