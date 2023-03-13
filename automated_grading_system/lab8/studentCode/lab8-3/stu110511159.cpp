#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int main() {

    while(1){
        cout<<"Enter the sentence: ";
        string str1;
        string arstr1[100];
        getline(cin,str1);
        if(str1 == "Stop the program")
            break;
        int nu1 = 0;
        int ini = 0;
        for(int i=0;i<str1.length();i++){
            if( isalpha( str1[i]) ){
                arstr1[nu1] += str1[i];
            }
            if( isalpha( str1[i-1] )&& !(isalpha(str1[i])) ){
                nu1++;
            }
        }
        for(int i=nu1;i>=0;i--){
            cout<<arstr1[i]<< ( (i==0) ? "" : " ");
        }
    cout<<endl;
    }
}


