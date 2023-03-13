#include<iostream>
#include<string>
using namespace std;

void count(string sen, int alp[]){
    int i, j, c;
    string temp;
    for(i = 0; i < sen.length(); i++){
        temp = sen.substr(i,1);
        c = (int)temp[0];
        if(c < 91 && c > 64){
            c -= 65;
            alp[c]++;
        }
        else if( c > 96 && c < 122){
            c -= 71;
            alp[c]++;
        }
    }
}

void show(int alp[]){
    int i;
    char c;
    for(i = 0; i < 52; i++){
        if(alp[i] != 0){
            if(i < 25){
                c = i+65;
            }
            else{
                c = i+71;
            }
            cout << c << ": ";
            cout << alp[i] << endl;;
        }
    }
    for(i = 0; i < 52; i++){
        alp[i] = 0;
    }
}

int main(){
    string sen;
    int alp[52] = {0};
    cout << "Enter message: ";
    getline(cin,sen);
    while(sen.compare("Stop") != 0){
        count(sen,alp);
        show(alp);
        cout << "Enter message: ";
        getline(cin,sen);
    }
    return 0;
}
