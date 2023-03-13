#include <bits/stdc++.h>
using namespace std;

void encoder(int len){
    string stren;
    char x[len]{0},y[len]{0};
    cin >> stren;
    for(int i=0; i<len; i++){
        if(i%2==0)x[i]=stren[i];
        if(i%2==1)y[i]=stren[i];
    }
    for(int j=0; j<len; j++)if(j%2==0)cout << x[j];
    for(int j=0; j<len; j++)if(j%2==1)cout << y[j];
    cout << endl;
}

void decoder(int len){
    string strde;
    char x[len]{0},y[len]{0};
    cin >> strde;
if(len%2==0){
    for(int i=0; i<len; i++){
        if(i<len/2)x[2*i]=strde[i];
        if(i>=len/2)y[2*(i-(len/2))+1]=strde[i];
    }
}
if(len%2==1){
    for(int i=0; i<len; i++){
        if(i<(len+1)/2)x[2*i]=strde[i];
        if(i>=(len+1)/2 && i<len)y[2*(i-(len/2))+1]=strde[i];
    }
}

    for(int j=0; j<len; j++){
        if(j%2==0)cout << x[j];
        if(j%2==1)cout << y[j];
    }
    cout << endl;
}


int main(){
    int len=0;
    char type;
    bool boo=0;

while(1){
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> type;

    switch(type){
        case '1' :
            cout << "Please enter sentences length: ";
            cin >> len;
            encoder(len);
            break; 

        case '2' :
            cout << "Please enter sentences length: ";
            cin >> len;
            decoder(len);
            break;
            
        case '3' :
            boo=1;
            break;

        default :
            cout << "invalid input" << endl;
            break;
    }
    len=0;
    if(boo)break;
    cout << endl;
}
return 0;
}
