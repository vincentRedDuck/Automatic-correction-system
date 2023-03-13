#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	char input = ' ';
	short mode = 0;

	cout << "Please enter a char : ";
	cin >> input;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >> mode;

	switch (mode){
		case 1:
			cout << input << endl;
			break;

		case 2:
			cout << int(input) << endl;
			break;

		case 3:
			//cout << resetiosflags(ios_base::dec) << setiosflags(ios::showbase | ios::oct) << input << endl;
			cout << "0" << oct << int(input) << endl;
			break;

		case 4:
			//cout << setiosflags(ios::showbase | ios::hex) << int(input) << endl;
			cout << "0x" << hex << int(input) << endl;
			break;

		default:
			cout << "No this option." << endl;
	}


	return 0;
}
