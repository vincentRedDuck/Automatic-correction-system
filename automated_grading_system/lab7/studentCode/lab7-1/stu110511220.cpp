#include<iostream>
using namespace std;

struct CARD {
    char suit;
    int value;
};
void insertionSort(CARD card[],int size);

int main () {
    CARD card[10];
    for(int i=0;i<10;i++) {
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    cout << endl;
    cout << "after sort" << endl;
    insertionSort(card,10);
    for(int i=0;i<10;i++) {
        cout << "suit: " << ((card[i].suit=='s') ? "Spades " : "Heart ") << "number: " << card[i].value << endl;
    }
    

    return 0;
}

void insertionSort(CARD card[],int size) {
    for(int i=1;i<size;i++) {
        CARD key1=card[i];
        int j=i-1;
        while(j>=0&&key1.value<card[j].value) {
            card[j+1]=card[j];
            j--;
        }
        card[j+1]=key1;
    }
    for(int i=1;i<size;i++) {
        if(card[i].suit=='h'||(card[i].suit=='s'&&card[i-1].suit=='s'))
            continue;
        else {
            int j=i-1;
            CARD key1=card[i];
            while(j>=0&&key1.suit=='s'&&card[j].suit=='h') {
                card[j+1]=card[j];
                j--;
            }
            card[j+1]=key1;    
        }
    }
    
}
