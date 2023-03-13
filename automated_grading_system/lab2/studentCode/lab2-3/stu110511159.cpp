#include <iostream>
#include <iomanip>
using namespace std;
int main(){


int b;
char a;
cout<<"Please enter a char : ";
cin>>a;

cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
cin>>b;


switch(b)
{
	case 1:
		cout<< a;
		break;
	case 2:
		cout<<std::dec<<int( a) ;
		break;
	case 3:
		cout<<std::oct<<"0"<<int( a);
		break;
	case 4:
		cout<<std::hex<< setiosflags(ios::showbase) <<int( a);
		break;
	default:
		cout<<"No this option.";
		break;






}
cout<<endl;
return 0;














}
