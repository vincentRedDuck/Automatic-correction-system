#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	char character;
	int type;

	cout << "Please enter a char : " ;
	cin >> character;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : " ;
	cin >> type;
	
	switch (type)
	{
		case 1:
			cout << character << endl;
			break;
		case 2:
			cout.setf(ios::dec);
			cout << (int)character << endl;
			break;
		case 3:
			
			cout << "0" << oct << (int)character << endl;
			break;
		case 4:
			cout << "0x"  << hex  << (int)character << endl;
			break;
		default:
			cout << "No this option." << endl;
	}
	return 0;	
}
