#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    while(1){
        int c[52] = {0};
        string s;
        cout << "Enter message: ";
        getline(cin, s);
        if(s == "Stop")
            break;
        for(int i = 0 ; i < s.length() ; i++){
            if(isalpha(s[i])){
                if(isupper(s[i]))
                    c[s[i]-'A']++;
                else
                    c[26+s[i]-'a']++;
            }   
        }
        for(int i = 0 ; i < 51 ; i++){
            if(c[i] != 0){
                if(i < 26)
                    cout << char(65+i) << ": " << c[i] << endl;
                else
                    cout << char(97+i-26) << ": " << c[i] << endl;
            }
        }
    }
    return 0;
}