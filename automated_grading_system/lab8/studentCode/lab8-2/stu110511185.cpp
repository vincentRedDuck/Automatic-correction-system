#include <iostream>
#include <string>
using namespace std;
int main(){
    string in;
    cout << "Enter message: ";
    getline(cin,in);
    while(in != "Stop"){
        int ucnt[26] = {0};//count of upper letters
        int lcnt[26] = {0};//count of lower letters
        for(int i=0; i <= in.length(); i++){
            if(65 <= (int)in[i] && (int)in[i] <= 90){
                ucnt[(int)in[i]-65]++;
            }
        }
        for(int i=0; i <= in.length(); i++){
            if(97 <= (int)in[i] && (int)in[i] <= 122){
                lcnt[(int)in[i]-97]++;
            }   
        }
        for(int j=0; j<=25; j++){
            if(ucnt[j]>0){
                cout << (char)(j+65) << ": " <<  ucnt[j] << endl;
            }
        }
        for(int j=0; j<=25; j++){
            if(lcnt[j]>0){
                cout << (char)(j+97) << ": " <<  lcnt[j] << endl;
            }
        }
        cout << "Enter message: ";
        getline(cin,in);
    }
    
}
