#include <iostream>
using namespace std;

int main(){
	char char0;
	int type;

        cout << "Please enter a char : ";
	cin >> char0;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >> type;
	cout.unsetf(ios::dec);
	switch(type){
		case 1:
			cout << char0 << endl;
			return 0;
		case 2:
			cout.setf(ios::dec);
                        break;
		case 3:
			cout.setf(ios::oct);
                        break;
		case 4:
			cout.setf(ios::hex);
                        break;
		default:
			cout << "No this option." << endl;
			return -1;
	}
	cout << showbase << char0 - 0 << endl;
}
