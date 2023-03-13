#include <iostream>
#include <iomanip>
using namespace std;
int main(){

double a;	
	
cout<<"Enter a num : "<<endl;
cin>>a;
cout<<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;

cout<<"number"<<setw(34)<<right <<"scientific"<<setw(20)<<right <<"signed"<<setw(20)<< right <<"precision4"<<endl;
cout<<fixed<<setw(20)<<left <<setprecision(6)<<a
<<setw(20)<<right<<uppercase<< scientific << a 
<<fixed <<setw(20)<< right << showpos << a; 
cout.unsetf(ios::fixed);
cout<<setw(20)<<right<<noshowpos<< showpoint<<fixed <<setprecision(4)<< a <<endl;



















}
