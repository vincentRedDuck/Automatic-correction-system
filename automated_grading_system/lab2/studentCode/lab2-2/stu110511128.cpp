//File ex2-2.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
          
	   double num;
        
	cout << "Enter a num : ";
	cin >> num;
	cout <<endl;  	
	cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" <<endl;
	cout << "number                        scientific              signed          precision4" <<endl;
	cout << setw(20) << fixed << setprecision(6) << left << num;              
	cout << uppercase << setw(20) << right << scientific << num;
	cout << setw(20) << fixed << setprecision(6) << showpos << right << num;

      	cout << setw(20) << fixed << setprecision(4) << noshowpos << right << num << endl;
	
	return 0;
}
		


