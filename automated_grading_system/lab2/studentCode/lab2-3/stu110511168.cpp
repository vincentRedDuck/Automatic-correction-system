#include <iostream>

using namespace std;

int main(){
	cout << "Please enter a char : ";
	char ch;
	cin >> ch;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	int n;
	cin >> n;
	//cout << "\n";
	
	switch (n){
		case 1:
			cout << ch;
			break;
		case 2:
			cout << int(ch);
			break;
		case 3:
			cout << oct << 0 << int(ch);
			break;
		case 4:
			cout << hex << 0 << "x" << int(ch);
			break;
		default:
			cout << "No this option.";
			break;
	}
	cout << endl;
}




