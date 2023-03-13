#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	double num = 0;

	cout << "Enter a num :" << endl;
	cin >> num;



	cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl
		<< setw(20) << left <<  "number";
	cout.unsetf(ios::left);
       	cout << setw(20) << "scientific";
	cout << setw(20) << "signed";
       	cout << setw(20); 
	cout << " precision4" << endl;

	cout.unsetf(ios::fixed);
	cout << setw(20) << fixed << left << num;
	cout.unsetf(ios::left);
	cout << setw(20) << uppercase << fixed << scientific << num;
	cout.unsetf(ios::fixed);
      	cout << setw(20) << fixed << showpos << num;
	cout.unsetf(ios::fixed);
	cout << setw(20) << noshowpos << fixed << showpoint << setprecision(4) << num << endl;
		
	return 0;
}
