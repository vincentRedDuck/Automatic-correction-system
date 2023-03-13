#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double num;

        cout << "Enter a num : ";
	cin >> num;
	cout << endl << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
	cout << left << setw(20) << "number" << right << setw(20) << "scientific" << setw(20) << "signed" << setw(20) << "precision4" << endl;

	cout << uppercase << left << setw(20) << fixed << setprecision(6)<< num << right << setw(20) << scientific << num << setw(20) << showpos << fixed << num << setw(20) << noshowpos << setprecision(4) << num << endl;

}
