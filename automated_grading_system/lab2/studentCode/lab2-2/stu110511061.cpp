#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "Enter a num : ";
	cin >> a;
	cout << endl << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
	cout << setw(20) << left<<"number";
	//cout.unsetf(ios::left);
       	cout << right << setw(20)<<"scientific";
       	cout << setw(20)<<"signed";
	cout << setw(20) <<"precision4"<< endl;
	cout << fixed << setprecision(6) <<setw(20) << left << a;
	cout << setw(20) << scientific <<uppercase<<right<<a;
	cout << setw(20) <<fixed<< showpos << a;
	cout << setw(20) << setprecision(4) <<noshowpos<< showpoint << a<<endl;
}
