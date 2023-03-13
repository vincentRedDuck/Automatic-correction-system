#include<iostream>
using namespace std;

const int cardnum = 10;

struct CARD{
    char suit;
    int value;
};

void sortAry(CARD ary[], int len) {
  for (int j=1; j<len; j++) {
    int key = ary[j].value;
    int i = j-1;
    while (i>=0 && ary[i].value>key) {
      ary[i+1].value = ary[i].value;
      i--; 
    }
    ary[i+1].value = key;
  }
}

int main() {
    CARD card[cardnum];
    for(int i=0; i<cardnum; i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    CARD spade[cardnum],heart[cardnum];
    int s=0,h=0;
    for(int i=0; i<cardnum; i++){//seperate
        if(card[i].suit == 's'){
            spade[s] = card[i];
            s++;
        }else if(card[i].suit == 'h'){
            heart[h] = card[i];
            h++;
        }
    }
    sortAry(spade,s);
    sortAry(heart,h);
    cout << endl << "after sort" << endl;
    for(int i=0; i<s; i++)
        cout << "suit: Spades number: " << spade[i].value << endl;
    for(int i=0; i<h; i++)
        cout << "suit: Heart number: " << heart[i].value << endl;
    return 0;
}
