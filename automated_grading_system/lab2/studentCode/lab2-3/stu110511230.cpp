#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	char cha;
	int choice;
	cout << "Please enter a char : ";
	cin >> cha;

	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >> choice ;
	switch(choice){
		case 1:
			cout << cha << endl;
			break;
		case 2:
			cout << (int)cha << endl;
			break;
		case 3:
			
			cout << std::oct << "0" << (int)cha << endl;
			break;
		case 4:
			
			cout << std::hex << "0x" << (int)cha << endl;
			break;
		default:
			cout << "No this option." << endl;
			break;
		}
	return 0;
}
