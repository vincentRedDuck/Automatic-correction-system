#include <iostream>
using namespace std;

struct CARD{
	char suit;
	int value;
};                           //here need ;

const int MAX = 10;
bool sh(CARD, CARD);
void InsertionSort(int, CARD []);

int main(){
	CARD card[MAX];
	for(int i=1; i<=MAX; i++){
		cout << "#" << i << " card suit: ";
		cin >> card[i-1].suit;
		cout << "#" << i << " card number: ";
		cin >> card[i-1].value;
	}
	
	cout << "\nafter sort\n";
	InsertionSort(MAX, card);

	return 0;
}

bool sh(CARD a, CARD b){
	if((a.suit == 'h') && (b.suit == 's')) return true;
	else if((a.suit == b.suit) && (a.value>b.value)) return true;
	else{
		return false;
	}
}
void InsertionSort(int MAX, CARD card[]){
	for(int j=1; j<MAX; j++){
		CARD key(card[j]); //CARD key = card[j];
		int i=j-1;
		while(i>=0 && (sh(card[i], key))){
			card[i+1] = card[i];
			i--;
		}
		card[i+1] = key;
	}
	for(int i=0; i<MAX; i++){
		cout << "suit: " << ((card[i].suit == 's')? "Spades number: ":"Heart number: ") << card[i].value << endl;
	}
}
