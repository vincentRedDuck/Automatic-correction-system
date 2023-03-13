#include <iostream>
using namespace std;

int main()
{

	char k;
	cout << "Please enter a char : ";
	cin >> k ;
	int type;
	cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
	cin >> type ;

	if(type==1)
	{
	
	cout << k << endl;

	}
	
	else if(type==2)
        {
	
	printf("%d",k);
	cout << endl;

        }
	
	else if(type==3)
        {
	
	cout << "0" ;	
	printf("%o",k);
	cout << endl;

        }

	else if(type==4)
        {
	
	cout << "0x" ;
	printf("%x",k);
	cout << endl;

        }

	else
	{
		cout << "No this option." << endl ;
	}


	return 0;
}
