#include <iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
};

void f(CARD c[],int size){
    for(int i = 1; i < size; i++){
        CARD key = c[i];
        int idx = i-1;
        while(idx >= 0 && c[idx].value < key.value){
            c[idx+1] = c[idx];
            --idx;
        }
        c[idx+1] = key;
    }
    for(int i = 8; i >= 0; i--){
        CARD key = c[i];
        int idx = i+1;
        while(c[idx].suit == 's'){
            c[idx-1] = c[idx];
            ++idx;
        }
        c[idx-1] = key;
    }
    for(int i = 1; i < size; i++){
        CARD key = c[i];
        int idx = i-1;
        while(c[idx].suit == 'h'){
            c[idx+1] = c[idx];
            --idx;
        }
        c[idx+1] = key;
    }
    for(int i = 0; i<size; i++){
        if(c[i].suit == 's'){
            cout << "suit: Spades number: "<< c[i].value << endl;
        }
        else{
            cout << "suit: Heart number: "<< c[i].value << endl;
        }
    }
}

int main(){
    int size = 10;
    CARD c[size];
    for(int i = 0; i < size; i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> c[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> c[i].value;
    }
    cout << endl;
    cout << "after sort" << endl;
    f(c,size);
    return 0;
}


