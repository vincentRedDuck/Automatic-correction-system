#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double num;
	cout<<"Enter a num : ";
	cin>>num;
	cout<<endl;

	cout<<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;
	cout<<"number"<<setw(34)<<"scientific"<<setw(20)<<"signed"<<setw(20)<<"precision4"<<endl;
        cout<<left<<setw(20)<<fixed<<showpoint<<setprecision(6)<<num;
	cout<<right<<setw(20)<< uppercase <<scientific<<num;
        cout.unsetf(ios::scientific);
	cout<<setw(20)<<fixed<<showpoint<<showpos<<setprecision(6)<<num;
	cout.unsetf(ios::showpos);
	cout<<setw(20)<<fixed<<showpoint<<setprecision(4)<<num<<endl;
	return 0;
}
	
