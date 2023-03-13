#include<iostream>
using namespace std;
struct CARD{
    char suit;
    int value;
};
void sortarray(int, int, CARD[]);

int main(){
CARD cards[10]; 
char suit;
int number;
CARD key;
int a=-1;
for(int i=0; i<10; i++){
    cout << "#" << i+1 << " card suit: ";
    cin >> suit;
    cout << "#" << i+1 << " card number: ";
    cin >> number;
    cards[i].suit = suit;
    cards[i].value = number;
}
cout << endl << "after sort\n";
for(int i=1; i<10; i++){ 
    for(int j=0; cards[i].suit=='s' && j<i; j++){
        key = cards[j];
        if(cards[j].suit == 'h'){
            cards[j] = cards[i];
            cards[i] = key;
            a = j;
            break;
        }
    }
}
if(a>=0){
    sortarray(1,a+1,cards);
    sortarray(a+2,10,cards);
    for(int i=0; i<a+1; i++){
        cout << "suit: Spades number: " << cards[i].value << endl;
    }
    for(int i=a+1; i<10; i++){
        cout << "suit: Heart number: " << cards[i].value << endl;
    }
}else {
    sortarray(1,10,cards);
    for(int i=0; i<10; i++){
        cout << "suit: Heart number: " << cards[i].value << endl;
    }
}
return 0;
}

void sortarray(int start, int end, CARD cards[]){
    CARD key2;
    for(int i=start; i<end; i++){
        key2 = cards[i];
        int j = i-1;
        while(j>=start-1 && cards[j].value > key2.value){
            cards[j+1] = cards[j];
            j--;
        }
        cards[j+1] = key2;
    }
}
