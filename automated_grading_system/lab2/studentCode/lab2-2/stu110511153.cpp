#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double a;
	  cout<<"Enter a num : ";
	  cin>>a;
	  cout<<"\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
		cout<<setw(20)<<left<<"number"<<setw(20)<<right<<"scientific"<<setw(20)<<right<<"signed"<<setw(20)<<right<<"precision4"<<endl;
	
cout<<left<<setw(20)<<fixed<<setprecision(6)<<a<<right<<setw(20)<<scientific<<uppercase<<a<<setw(20)<<fixed<<showpos<<right<<a;
	cout.unsetf(ios::showpos);
	cout<<setw(20)<<fixed<<setprecision(4)<<right<<a<<endl;


return 0;	
}

