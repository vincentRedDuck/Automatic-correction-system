#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	double number;

	cout << "Enter a num : " << endl;
	cin >> number;

	cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
	cout << "number                        scientific              signed          precision4" << endl;
	cout << left << setw(20) << fixed << setprecision(6) << number;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific | ios::uppercase);
       	cout << right << setw(20) << number;
	cout << setw(20) << fixed << setprecision(6) << showpos << number;
	cout << setw(20) << fixed << noshowpos << setprecision(4) << number << endl;
	
}
