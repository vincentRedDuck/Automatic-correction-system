#include <iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Enter your score : ";
	cin>>a;
	switch(a)
	{
		case 80 ... 100:
		
			cout<<"You got a grade : "<<"A\n";
			break;
		case 70 ... 79:
		
			cout<<"You got a grade : "<<"B\n";
			break;
		case 60 ... 69:

		cout<<"You got a grade : "<<"C\n";
			break;
		case 50 ... 59:
	
			cout<<"You got a grade : "<<"D\n";
			break;
		default:
		
			cout<<"You got a grade : "<<"E\n";
			break;	
			
	}
	return 0;
}
