//Exercise 2-2
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double num;
	cout << "Enter a num : ";
	cin >> num;
	cout << "\n";
	for(int n=0;n<8;n++)
		cout << "123456789~";
	cout << "\n";
	cout << setw(20) << left << "number";
        cout.unsetf(ios::left);	
	cout << setw(20) << "scientific" << setw(20) << "signed" << setw(20) << "precision4" << endl;

	cout << setw(20) << left;
	cout << fixed << setprecision(6) << num;
        cout.unsetf(ios::left);
	cout << setw(20) << setiosflags(ios::uppercase) << scientific << setprecision(6) << num;
	cout.unsetf(ios::scientific);
	cout << setw(20) << fixed << setprecision(6) << setiosflags(ios::showpos) <<  num;
	cout.unsetf(ios::showpos);
	cout << setw(20) << fixed << setprecision(4) <<  num << endl;
	

	return 0;
}
