#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double in;
	cout<<"Enter a num : ";
	cin>>in;
	cout<<endl;
	for(int i=1;i<9;i++)
		cout<<"123456789~";
	cout<<endl;

	cout<<setw(20)<<left<<"number"<<setw(20)<<right<<"scientific"<<setw(20)<<"signed"<<setw(20)<<"precision4"<<endl;
	
	cout<<setw(20)<<left<<fixed<<in;
	cout<<setw(20)<<right<<uppercase<<scientific<<in;
	cout<<setw(20)<<right<<showpos<<fixed<<in;
	cout<<setw(20)<<right<<setprecision(4)<<noshowpos<<fixed<<in<<endl;
	
	return 0;







}
