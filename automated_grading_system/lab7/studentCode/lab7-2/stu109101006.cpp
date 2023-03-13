#include <iostream>

using namespace std;

int main () {
	short mode = 0;
	char input[101] = {'\0'};
	char output[101] = {'\0'};
	int length = 0;

	cout << "1: encoder 2: decoder 3: quit: ";
	cin >> mode;


	while (mode != 3) {

		if (mode < 1 || mode > 3) {
			cout << "invalid input" << endl;
			cout << endl << "1: encoder 2: decoder 3: quit: ";
			cin >> mode;
			continue;
		}

		for (int i = 0; i < 101; i++) {
			output[i] = '\0';
		}

		cout << "Please enter sentences length: ";
		cin >> length;
		cin >> input;

		if (mode == 1){
			for (int i = 0; i < length; i++) {
				output[i] = (2 * i < length) ? input[i * 2] : input[(i - ((length+1)/2)) * 2  + 1];  
			}
			cout << output << endl;
		}

		else if (mode == 2) {
			for (int i = 0; i < length; i++) {
				output[i] = (i % 2 == 0) ? input[i / 2] : input[i / 2 + (length+1)/2];
			}
			cout << output << endl;
		}



		cout << endl << "1: encoder 2: decoder 3: quit: ";
		cin >> mode;
	}

	return 0;
}
