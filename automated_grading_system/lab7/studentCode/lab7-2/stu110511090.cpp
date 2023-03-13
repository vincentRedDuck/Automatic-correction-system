#include <iostream>
using namespace std;
void encoder(char c[], int len){
    for(int i = 0; i < len; i+=2){
        cout << c[i];
    }
    for(int i = 1; i < len; i+=2){
        cout << c[i];
    }
    cout << endl;
}
void decoder(char c[], int len){
    for(int i = 0; i < len/2; i++){
        cout << c[i] << c[len/2+i];
    }
    cout << endl;
}

int main(){
    int x;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> x;
    while(x != 3){
    if(x == 1){
        int len;
        char c[100];
        cout << "Please enter sentences length: ";
        cin >> len;
        cin >> c;
        encoder(c,len);
    }
    else if(x == 2){
        int len;
        char c[100];
        cout << "Please enter sentences length: ";
        cin >> len;
        cin >> c;
        decoder(c,len);
    }
    else{
        cout << "invalid input" << endl;
    }
    cout << endl;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> x;
    }
    return 0;
}
