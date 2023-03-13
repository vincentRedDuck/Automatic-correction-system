#include <iostream>

using namespace std;

struct CARD {
	char suit;
	int value;
};

int main () {
	CARD cardin[10] = {};
	CARD temp = {};
	bool sorted = 0;


	for (int i = 0; i < 10; i++) {
		cout << "#" << i+1 <<" card suit: ";
		cin >> cardin[i].suit;
		cout << "#" << i+1 <<" card number: ";
		cin >> cardin[i].value;
	}
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < 9; i++){
			if (cardin[i+1].value < cardin[i].value) {
				sorted = 0;
				temp = cardin[i];
				cardin[i] = cardin[i+1];
				cardin[i+1] = temp;		
			}	
		}
	}

	sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < 9; i++){
			if (int(cardin[i+1].suit) > int(cardin[i].suit)) {
				sorted = 0;
				temp = cardin[i];
				cardin[i] = cardin[i+1];
				cardin[i+1] = temp;		
			}	
		}
	}



	cout << endl << "after sort" << endl;

	for (int i = 0; i < 10; i++){
		cout << "suit: ";
		if (cardin[i].suit == 's'){
			cout << "Spades";
		}
		else if (cardin[i].suit == 'h') {
			cout << "Heart";
		}

		cout << " number: " << cardin[i].value << endl;
	}

	return 0;
}
