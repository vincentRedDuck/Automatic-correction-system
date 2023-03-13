#include<iostream>
#include<iomanip>
using namespace std;
int main(){

	double a;
	cout<<"Enter a num : ";
        cin>>a;
	cout<<"\n\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
	cout<<"number                        scientific              signed          precision4\n";
	cout<<left<<fixed<<setprecision(6)<<setw(20)<<a;
	cout<<setiosflags(ios::right)<<setw(20)<<uppercase<<scientific<<a;
	cout<<fixed<<setw(20)<<showpos<<a;
	cout<<setw(20)<<noshowpos<<setprecision(4)<<a<<endl;
        return 0;
}
