#include<iostream>
using namespace std;

const int MAX_SIZE = 10;
struct CARD {
    char suit;
    int value;
};
void fillAry(CARD ar[]);
void sort(CARD ar[]);


int main () {
    CARD card[MAX_SIZE];
    fillAry(card);
    cout << endl;
    cout << "after sort" << endl;
    sort(card);
return 0;
}

void fillAry(CARD ar[]) {
    for (int i=1; i<=10; i++) {
        cout << "#" << i << " card suit: ";
        cin >> ar[i-1].suit ;   
        cout << "#" << i << " card number: ";
        cin >> ar[i-1].value;
    }
}
void sort(CARD ar[]) {
    int key, i;
    for (int j=1; j<10; j++) {
        key = ar[j].value;
        i = j-1;
        while (i>=0 && ar[i].value > key) {
            ar[i+1] = ar[i];
            i--;
        }
        ar[i+1].value = key;
    }
    for (int i=0; i<10 ;i++) {     
        if (ar[i].suit =='s')
            cout << "suit: " << "Spades " << "number: " << ar[i].value << endl;
    }
    for (int i=0; i<10; i++) {
        if (ar[i].suit =='h')
            cout << "suit: " << "Heart " << "number: " << ar[i].value << endl;
     }    
}
