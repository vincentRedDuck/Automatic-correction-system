#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long double num;
	cout << "Enter a num : ";
	cin >> num;
	cout << endl << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<< endl ;
	cout <<         "number                        scientific              signed          precision4"<< endl ;   
	
	cout << left << setw(20) << fixed << setprecision(6) << num ;
	cout <<	setw(20) << setiosflags(ios::right) << scientific << uppercase << num ;
	cout << setw(20) << setiosflags(ios::showpos) << fixed  << num ;
	cout << setw(20) << fixed << setprecision(4) << noshowpos << num << endl;

	return 0;
}
