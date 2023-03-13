#include <iostream>
#include <cstring>

using namespace std;

int main () {
	char input [1000];
	int count [52];
	
	while (true) {
	
		cout << "Enter message: ";
		cin.getline(input, 1000);
		
		if (strcmp(input, "Stop") == 0) break;

		// Count

		for (int i = 0; i < 52; i++) {
			count [i] = 0;
		}

		for (int i = 0; i < strlen(input); i++) {
			if (int(input [i]) >= 65 && int(input [i]) <= 90) {
				count [int(input [i]) - 65] ++;
			}
			
			else if (int(input [i]) >= 97 && int(input [i]) <= 122) {
				count [int(input [i]) - 97 + 26] ++;
			}
		}

		// Output

		for (int i = 0; i < 26; i++){
			if (count [i] != 0) {
				cout << char(i + 65) << ": " << count [i] << endl;
			}
		}
		for (int i = 0; i < 26; i++){
			if (count [i + 26] != 0) {
				cout << char(i + 97) << ": " << count [i + 26] << endl;
			}
		}


	}
	

}
