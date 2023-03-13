#include <bits/stdc++.h>
using namespace std;

struct CARD{
    char suit[10];
    int value[10];
};

int main(){

    int spades[10],heart[10],k=0,h=0;
    CARD v;

    for(int i=0; i<10; i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> v.suit[i];

        cout << "#" << i+1 << " card number: ";
        cin >> v.value[i];

        if(v.suit[i]=='s'){
            spades[k]=v.value[i];
            k++;
        }
        
        if(v.suit[i]=='h'){
            heart[h]=v.value[i];
            h++;
        }
    }

    cout << endl << "after sort" << endl;
    int temp=0;

    for(int i=0; i<=k; i++){
        for(int j=i+1; j<=k; j++){
            if(spades[i]>spades[j]){
                temp=spades[i];
                spades[i]=spades[j];
                spades[j]=temp;
            }
        }
    }
    for(int i=0; i<k; i++){
        cout << "suit: Spades number: " << spades[i] << endl;
    }

    temp=0;

    for(int a=0; a<=h; a++){
        for(int b=a+1; b<=h; b++){
            if(heart[a]>heart[b]){
                temp=heart[a];
                heart[a]=heart[b];
                heart[b]=temp;
            }
        }
    }
    for(int j=0; j<h; j++){
        cout << "suit: Heart number: " << heart[j] << endl;
    }

return 0;
}
