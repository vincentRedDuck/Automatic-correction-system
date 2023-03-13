#include<bits/stdc++.h>

using namespace std;

int main() {
    
    string b,reg,c;
    while(1){
    cout<<"Enter the sentence: ";
    b.clear();
    getline(cin,b);
    bool x=1;
    reg.clear();
    
    c.clear();
    if(b=="Stop the program")break;
    for(int i=b.length()-1;i>=0;i--){

        if(isalpha(b.at(i))!=0){
        x=1;
        reg+=b.at(i);
        }
        else {
            for(int k=reg.length()-1;k>=0;k--){
                cout<<reg.at(k);
            }
            
                if(x){
                    cout<<" ";
                    x=0;
                }
            
        reg.clear(); 
        }
    }
    for(int l=reg.length()-1;l>=0;l--)
    cout<<reg.at(l);
    cout<<endl;
    }
return 0;
}

