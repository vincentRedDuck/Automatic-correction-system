#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main () {
	string input;
	int sublen = 0;

	while (true) {
	
		cout << "Enter the sentence: ";
		getline(cin, input);
		
		if (input == "Stop the program") break;
		
		sublen = 0;

		// cout << input.length() << endl;

		for (int i = input.length() - 1; i >= 0; i--) {
			// cout << i << " " << sublen << endl;

			if (int(input [i]) >= 65 && int(input [i]) <= 90) {
				sublen++;
			}
			else if (int(input [i]) >= 97 && int(input [i]) <= 122) {
				sublen++;
			}
			else {
				if (sublen != 0) {
					cout << input.substr(i + 1, sublen) << " ";
					sublen = 0;
				}
			}
		}
		if (sublen != 0) {
			cout << input.substr(0, sublen) << " ";
			sublen = 0;
		}
		cout << endl;



	}
	

}
