#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double num;
	cout << "Enter a num :" << endl;
	cin >> num;
	cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
	cout << "number                        scientific              signed          precision4" << endl;
	cout << fixed << setprecision(6) << setw(20) << left << num;
	cout << fixed << setw(20) << scientific << right << setiosflags(ios::uppercase) << num;
	cout << fixed << setw(20) << showpos << num;
	cout << noshowpos << fixed << setw(20) << setprecision(4) << num << endl;

	return 0;
}	
