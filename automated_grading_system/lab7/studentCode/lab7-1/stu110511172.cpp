#include<iostream>
using namespace std;

struct CARD{
    char suit;
    int value;};


int main(){

    CARD card[10];

    for(int i=0;i<10;i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    
    for(int i=1;i<10;i++){
        CARD key = card[i];
        int j=i;
        while( j>0 && key.suit > card[j-1].suit){
            card[j] = card[j-1];
            card[j-1] = key;
            j--;
        }
    }

    for(int i=0;i<10;i++){
        CARD key = card[i];
        int j=i;
        while(card[j].suit == 's' && j>0 && key.value < card[j-1].value){
            card[j] = card[j-1];
            card[j-1] = key;
            j--;
        }
        while(card[j-1].suit == 'h' && j>0 && key.value < card[j-1].value){
            card[j] = card[j-1];
            card[j-1] = key;
            j--;
        }
    }
    cout << endl;
    cout << "after sort"<<endl;

    for(int i=0;i<10;i++){
        cout << "suit: " << (card[i].suit=='s'?"Spades":"Heart") << " number: " << card[i].value << endl;
}
return 0;
}
