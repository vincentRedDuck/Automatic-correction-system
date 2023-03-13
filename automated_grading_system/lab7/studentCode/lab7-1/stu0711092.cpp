#include<iostream>
using namespace std;
 
struct CARD{
	char suit;
	int value;
};
void display(CARD [],int);
int main(){

	const int Max = 10;
	CARD card[Max];
	for (int i = 0;i<10;i++){
		cout <<"#" <<i+1 <<" card suit: ";
		cin >> card[i].suit;
		cout <<"#" <<i+1 <<" card number: ";
		cin >> card[i].value;
	}
	cout <<"\n";
	display(card,Max);

}
void display(CARD card[],int Max){
	cout << "after sort"<< endl;
	for(int i=1;i<=9;i++){
	int nu = 0;
	char su;

	for(int j = 1;j<i+1;j++){
	su = card[i-j+1].suit;
	nu = card[i-j+1].value;

	if(su == card[i-j].suit){
	if(nu < card[i-j].value){
	card[i-j+1].suit = card[i-j].suit;
	card[i-j+1].value=card[i-j].value;
	card[i-j].value = nu;
	card[i-j].suit = su;
	}
	}

	if(su == 's' && card[i-j].suit == 'h'){
	card[i-j+1].suit = card[i-j].suit;
	card[i-j+1].value=card[i-j].value;
	card[i-j].value = nu;
	card[i-j].suit = su;	
	}
	}
	}
	for(int i=0;i<10;i++){
	cout <<"suit: ";
	if(card[i].suit == 's'){
	cout <<"Spades number: ";
	}else{
	cout <<"Heart number: ";
	}
	cout << card[i].value << endl;
	}
}
