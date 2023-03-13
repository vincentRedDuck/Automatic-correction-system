#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	char ASCII;
	int choose;
	cout <<"Please enter a char : ";
	cin >>ASCII;
	cout <<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >>choose;
	switch(choose){
		case 1:
			cout<< ASCII<<endl;
			break;
		case 2:
			cout.setf(ios::dec);
			cout<<int(ASCII)<<endl;
			break;
		case 3:
			cout << "0"<<oct<<int(ASCII)<<endl;
			break;
		case 4:
			cout <<"0x"<<hex<<int(ASCII)<<endl;
			break;
		default:
			cout<<"No this option."<<endl;
	}
	
		




}
