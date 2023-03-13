#include<iostream>
using namespace std;
const int size =10;
struct CARD{
    char suit;
    int value;
};
void InsertionSort(CARD [],int);
int main(){
    CARD card[10];
    for (int i=0;i<size;i++) {
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    cout << endl << "after sort" << endl;
    InsertionSort(card,size);
    for (int i=0;i<size;i++) {
        if (card[i].suit == 's') 
            cout << "suit: Spades number: " << card[i].value << endl;
    }
    for (int i=0;i<size;i++) {
        if (card[i].suit == 'h')
            cout << "suit: Heart number: " << card[i].value <<endl;
    }
    return 0;
}

void InsertionSort(CARD card[],int size){
         
    for (int i =0;i < size;i++) {
        CARD key = card[i];
        int j=i-1;
        while (key.value < card[j].value && j>=0) {
                card[j+1] =card[j];
                j--;
            }
            card[j+1]=key;
        
    }
} 
