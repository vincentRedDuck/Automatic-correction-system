#include<iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
};

int main(){
    CARD card[10];
    int i, j, temp;
    for(i = 0; i < 10; i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    for(i = 0; i < 9; i++){
        for( j = i+1; j < 10; j++){
            if(card[i].suit == 'h' && card[j].suit == 's'){
                card[i].suit = 's';
                card[j].suit = 'h';
                temp = card[i].value;
                card[i].value = card[j].value;
                card[j].value = temp;
            }
        }
    }
    cout << endl << "after sort" << endl;
    for(i = 0; i < 9; i++){
        for(j = i+1; j < 10; j++){
            if(card[i].suit ==  card[j].suit && (card[i].value > card[j].value)){
                temp = card[i].value;
                card[i].value = card[j].value;
                card[j].value = temp;
            }
        }
    }
    for(i = 0; i < 10; i++){
        if(card[i].suit == 's'){
            cout << "suit: Spades number: " << card[i].value << endl;
        }
        else{
            cout << "suit: Heart number: " << card[i].value << endl;
        }
    }    
    return 0;
}
