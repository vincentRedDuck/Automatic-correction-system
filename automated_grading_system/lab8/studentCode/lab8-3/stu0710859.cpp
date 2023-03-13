#include<iostream>
#include<string>
using namespace std;

void rev(string sen){
    string temp;
    int i, j= sen.length(), k, c, clen, d = 1;
    for(i = sen.length()-1; i >= 0; i--){
        c = (int)sen[i];
        if(c > 64 && c < 91){
            k = i;
            d = 0;
        }
        else if(c > 96 && c < 122){
            k = i;
            d = 0;
        }
        else{
            if(d == 0){
                clen = j-k;
                temp = sen.substr(k, clen);
                cout << temp << " ";
                k = i;
                d = 1;
            }
            j = i;
        }
    }
    if(d == 0){
        temp = sen.substr(0,j);
        cout << temp;
    }
    cout << endl;
}

int main(){
    string sen;
    cout << "Enter the sentence: ";
    getline(cin,sen);
    while(sen.compare("Stop the program") != 0){
        rev(sen);
        cout << "Enter the sentence: ";
        getline(cin, sen);
    }
    return 0;
}
