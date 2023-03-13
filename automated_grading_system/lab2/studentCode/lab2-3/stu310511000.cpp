#include<iostream>
using namespace std;

int main(){
	char in,type;
	cout<<"Please enter a char : ";
	cin>>in;
	cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin>>type;

	switch(type){
		case '1':
			cout<<in<<endl;
			break;
		case '2':
			cout<<(int)in<<endl;
			break;
		case '3':
			cout<<showbase<<oct<<(int)in<<endl;
			break;
		case '4':
			cout<<showbase<<hex<<(int)in<<endl;
			break;
		default:
			cout<<"No this option.\n";
			break;
	}	





}
