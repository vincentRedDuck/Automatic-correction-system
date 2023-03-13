#include <iostream>
using namespace std;

const int MAX_NUM = 10;
struct CARD {
    char suit;
    int value;
};
void sortAry(CARD [], int);

int main() {
    CARD card1[MAX_NUM];
    CARD card2[MAX_NUM];
    char tmp;
    int d = 0, f = 0;
    for(int i=0; i<MAX_NUM; i++) {
        cout << "#" << i+1 << " card suit: ";
        cin >> tmp;
        if(tmp=='s') {
            cout << "#" << i+1 << " card number: ";
            cin >> card1[d++].value;
        }
        else {
            cout << "#" << i+1 << " card number: ";
            cin >> card2[f++].value;
        }
        
    }
    cout << endl << "after sort" << endl;
    sortAry(card1, d+1);
    for(int i=0; i<d; i++) {
        cout << "suit: Spades number: " << card1[i].value << endl;
    }
    sortAry(card2, f+1);
    for(int i=0; i<f; i++) {
        cout << "suit: Heart number: " << card2[i].value << endl;
    }
    return 0;
}

void sortAry(CARD card[], int len) {
    for(int j=1; j<len; j++) {
        int key = card[j].value;
        int i = j-1;
        while(i>=0 && card[i].value>key) {
            card[i+1].value = card[i].value;
            i--;
        }
        card[i+1].value = key;
    }   
}
