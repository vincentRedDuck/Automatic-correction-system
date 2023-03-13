#include <iostream>
using namespace std;


struct CARD {
    char suit;
    int value;
};

void initAry (CARD v[]);
void sortS (CARD v[], CARD s[], CARD h[], int& num1, int& num2);
void sortN (CARD v[], int sz);

int main () {
    CARD card[10];
    initAry(card);
    for (int idx=0; idx<10; idx++) {
        cout << "#" << idx+1 << " card suit: ";
        cin >> (card[idx]).suit;
        cout << "#" << idx+1 << " card number: ";
        cin >> (card[idx]).value;
    }
    
    cout << endl;
    cout << "after sort\n";
/*
    for (int i=0; i<10; i++) {
        cout << (card[i]).suit << " " << (card[i]).value << endl;
    }
*/
    int s_sz = 0, h_sz = 0;
    CARD spade [10];
    CARD heart [10];
    sortS (card, spade, heart, s_sz, h_sz);
    sortN (spade, s_sz);
    sortN (heart, h_sz);

    for (int i=0; i<s_sz; i++) {
            cout << "suit: Spades number: " << spade[i].value << endl;    
    }
    for (int i=0; i<h_sz; i++) {
            cout << "suit: Heart number: " << heart[i].value << endl;
    }

    return 0;
}

void initAry (CARD v[]) {
    for (int i=0; i<10; i++) {
        v[i].suit = 'a';
        v[i].value = 0;
    }
}

void sortS (CARD v[], CARD s[], CARD h[], int& num1, int& num2) {
    for (int i=0; i<10; i++) {
        if (v[i].suit == 's') {
            s [num1] = v [i];
            num1++;
        } else {
            h [num2] = v [i];
            num2++;
        }
    }
}

void sortN (CARD v[], int sz) {
    for (int j=1; j<sz; j++) {
        int key = v[j].value;
        int i = j - 1;
        while (i>=0 && v[i].value>key) {
            v[i+1].value = v[i].value;
            i--;
        }
        v[i+1].value = key;
    }
}
