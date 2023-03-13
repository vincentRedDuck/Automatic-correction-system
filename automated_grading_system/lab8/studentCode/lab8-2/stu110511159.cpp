#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int main() {
  while(1){
    string str;
    cout<<"Enter message: ";
    getline(cin,str);
    if(str == "Stop" )
        break;
    int s[53]={};
    for(int i=0;i<str.length();i++){
        int u = int(str[i]-64);
        int l = int(str[i]-96);
        if( 26>=u && u >=1 ){
            s[u]++;
        }
        if(26>=l && l>=1){
            s[l+26]++;
        }
    }
    for(int i=1;i<53;i++){
        if(i<27 && s[i]!=0){
            cout<<char(64+i)<<": "<<s[i]<<endl;
        }
        if(i>=27 && s[i]!=0){
            cout<<char(96+i-26)<<": "<<s[i]<<endl;
        }
    }
  }
}

