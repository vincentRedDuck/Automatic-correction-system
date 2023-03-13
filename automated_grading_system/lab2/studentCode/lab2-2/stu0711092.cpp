#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	double num;
	cout <<"Enter a num : ";
	cin >> num ;
	cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<< endl;
	cout << "number                        scientific              signed          precision4"<< endl;
	cout <<left<<setw(20)<<fixed<<setprecision(6)<<num;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific | ios::uppercase);
	cout <<right<<setw(20)<<num;
	cout<<right<<setw(20)<<fixed<<setiosflags(ios::showpos)<<num;
	cout<<right<<setw(20)<<fixed<<noshowpos<<setprecision(4)<<num<<endl;	

}
