#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double number;
    cout << "Enter a num : ";
    cin  >> number;
    cout << endl;

    cout <<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;

    cout <<"number                        scientific              signed          precision4"<<endl;
    //cout << endl;
    cout<<uppercase;
    cout << setw(20)<<left << fixed      <<setprecision(6)<< number;
    
    cout << setw(20)<<right<< scientific <<setprecision(6)<< number;
    cout.unsetf(ios::scientific);
    cout << setw(20)<<right<< showpos    <<fixed<<setprecision(6)<< number;
    cout.unsetf(ios::showpos);
    cout << setw(20)<<right<< fixed      <<setprecision(4)<< number;    
    cout << endl;

}
