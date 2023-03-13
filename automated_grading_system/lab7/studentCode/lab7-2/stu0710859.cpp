#include<iostream>
using namespace std;

void encoder(int length){
    char sen[100];
    int i, j;
    for(i = 0; i < length; i++){
        cin >> sen[i];
    }
   // if( length%2 == 1){
        for(i = 0; i < length; i += 2){
            cout << sen[i];
        }
        for(i = 1; i < length; i += 2){
            cout << sen[i];
        }
   // }
   // else{
        
   // }
    cout << endl << endl;
    return;
}

void decoder(int length){
    int i, n;
    char sen[100];
    for(i = 0; i < length; i++){
        cin >> sen[i];
    }
    if(length%2 == 0){
        for(i = 0; i < length/2; i++){
            cout << sen[i] << sen[i+(length/2)];
        }
    }
    else if(length%2 != 0){
        for(i = 0; i < length/2; i++){
            cout << sen[i] << sen[i+(length/2)+1];
        }
        cout << sen[length/2];
    }
    cout << endl << endl;
    return;
}

int main(){
    int length, n;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> n;
    while(n != 3){
        if(n == 1){
            cout << "Please enter sentences length: ";
            cin >> length;
            encoder(length);
        }
        else if(n == 2){
            cout << "Please enter sentences length: ";
            cin >> length;
            decoder(length);
        }
        else{
            cout << "invalid input" << endl << endl;
        }
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> n;
    }
    return 0;
}
