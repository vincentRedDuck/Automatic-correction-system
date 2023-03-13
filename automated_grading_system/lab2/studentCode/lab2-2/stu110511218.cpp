#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
cout<<"Enter a num : ";
double num;
cin>>num;
cout<<endl;
cout<<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
cout<<"number                        scientific              signed          precision4\n";
cout<<setiosflags(ios::left)<<setw(27)<<fixed<<setprecision(6)<<num<<resetiosflags(ios::left)<<setw(13)<<uppercase<<scientific<<num<<fixed<<setw(20)<<showpos<<num<<noshowpos<<setw(20)<<setprecision(4)<<num;
cout<<endl;
}
