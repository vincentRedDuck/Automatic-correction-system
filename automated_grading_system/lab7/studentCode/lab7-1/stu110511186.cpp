#include<iostream>
using namespace std;
struct CARD{
   char suit;
   int value;
};

void sort(CARD[], int);

int main(){
  CARD card[10];
  int i=0;
  for(i=0;i<=9;i++){
    cout <<"#"<< i+1 <<" card suit: ";
    cin >> card[i].suit;
    cout <<"#"<< i+1 <<" card number: ";
    cin >> card[i].value;
  }
  sort(card,10);
  cout <<"\n"<<"after sort"<< endl;
  int a=0;
  for(a=0;a<=9;a++){
    if(card[a].suit == 's')
        cout <<"suit: Spades number: "<< card[a].value <<endl;
    if(card[a].suit == 'h')
        cout <<"suit: Heart number: "<< card[a].value <<endl;
  }
return 0;
}


void sort(CARD arr[], int size){
    for(int i=1;i<size;i++){
        CARD key1 = arr[i];
        int j = i-1;
        while((key1.suit > arr[j].suit ||( key1.suit == arr[j].suit && key1.value < arr[j].value))  && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key1;
    }
}
