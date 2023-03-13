#include <iostream>
using namespace std;
int main()
{
	int a;
	int b;
	cout << "Enter your score : ";
	cin >> a;
	b = a/10;
	switch(b)
	{
		case 10:
		case 9:
		case 8:
			cout<<"You got a grade : A"<<endl;
			break;
		case 7:
			cout<<"You got a grade : B"<<endl;
			break;
		case 6:
			cout<<"You got a grade : C"<<endl;
			break;
		case 5:
			cout<<"You got a grade : D"<<endl;
			break;
		default:
			cout<< "You got a grade : E"<<endl;
	}
}


