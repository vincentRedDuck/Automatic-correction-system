#include<iostream>
using namespace std;

struct CARD{
	char suit;
	int number;
};

CARD card[11];
int sc = 0;
int hc = 0;
int swc = 0;
int main (){
	for(int i = 0;i < 10;i++){
		cout << "#" << i+1 << " card suit: ";
		cin >> card[i].suit;
		
		cout << "#" << i+1 << " card number: ";
		cin >> card[i].number;
		
	}
	cout << endl;
	for (int i = 0;i < 10;i++){
		if(card[i].suit=='s')
			sc += 1;
	}
	for (int i = 0;i < 10;i++){
		if(card[i].suit=='s'){
			card[10]=card[swc];
			card[swc]=card[i];
			card[i]=card[10];
			swc++;
		}
	}
	for(int j = 1; j < sc; j++){
		int key = card[j].number;
		int k = j-1;
		while (key < card[k].number && k >= 0){
			card[k+1]=card[k];
			k--;
		}
		card[k+1].number = key;
	}
        for(int j = sc; j < 10; j++){
                int key = card[j].number;
                int k = j-1;
                while (key < card[k].number && k >= sc){
                        card[k+1]=card[k];
                        k--;
                }
                card[k+1].number = key;
	}
	cout<< endl << "after sort" << endl;
	for (int i = 0 ; i < sc ;i++){
		cout << "suit: Spades number: " << card[i].number << endl;
}
	for (int i = sc ; i < 10 ;i++){
		cout << "suit: Heart number: " << card[i].number << endl;
	}
return 0;
	
}
