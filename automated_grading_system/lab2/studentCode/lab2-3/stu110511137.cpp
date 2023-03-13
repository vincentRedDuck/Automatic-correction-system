//Excercise 2-3
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	char cha;
	int type;
	cout << "Please enter a char : ";
	cin >> cha;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >> type;
	switch (type){
		case 1:
			cout << cha << endl;
			break;
		case 2:
			cout << std::dec << int(cha) << endl;
			break;
		case 3:
			cout << std::oct << "0" << int(cha) << endl;
			break;
		case 4:
			cout << std::hex << showbase << setw(4) << int(cha) << endl;
			break;
		default:
			cout << "No this option." << endl;
	}
	return 0;
}



