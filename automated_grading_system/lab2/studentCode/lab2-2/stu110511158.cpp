#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
  double number;
  cout << "Enter a num : ";
  cin >> number;
cout<<endl;
cout<<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;

  cout << setw(20) <<left<< "number" <<setw(20)<<right<< "scientific" <<setw(20)<<right<< "signed" <<setw(20)<<right<< "precision4"<<endl;
cout<<setw(20)<<left<<fixed<<setprecision(6)<< number; 
cout <<setw(20)<<right<<uppercase<<scientific<< number;
cout <<setw(20)<<right<<fixed<<showpos<< number;
cout.unsetf(ios::showpos);
cout <<setw(20)<<right<<fixed<< setprecision(4) <<number<<endl;
  return 0;
} 
