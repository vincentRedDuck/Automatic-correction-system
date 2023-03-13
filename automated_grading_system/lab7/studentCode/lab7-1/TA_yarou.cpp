#include <iostream>

using namespace std;

struct CARD{
    char suit;
    int value;
};
void InsertionSort(CARD c[]){

    for(int i = 0; i < 10; i++){

        CARD ctmp = c[i];
        int j = i - 1;

       while(j >= 0 && (c[j].suit > ctmp.suit ||((c[j].suit == ctmp.suit) && (c[j].value > ctmp.value)))){
 //       while(j >= 0 && (c[j].suit > ctmp.suit)){
            c[j+1] = c[j];
            j--;
        }
        c[j+1] = ctmp;
    }
}
void DisplayArray(CARD c[]){


    for(int i = 0; i < 10; i++){
        cout << "suit: ";
        switch(c[i].suit){
        case's':
            cout << "Spares";
            break;
        case'h':
            cout << "Heart";
            break;
        }
        
        cout << " number: " << c[i].value << endl;
    }
}
int main(){

    CARD card[10];
    for(int i = 0; i < 10; i++){
        cout << "#"<<i+1<<" card suit: ";
        cin >> card[i].suit;
        cout << "#"<<i+1<<" card number: ";
        cin >> card[i].value;
    }
//    for(int i = 0; i < 10; i++){
//        cout << "#"<<i+1<<" card suit: " << card[i].suit << endl;
//        cout << "#"<<i+1<<" card number: " << card[i].value << endl;
//    }
    cout << endl << "after sort" << endl;
    InsertionSort(card);
    DisplayArray(card);
    return 0;
}
