#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a;
    cout << "Enter a num :";
    cin >> a;

    cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout << setw(20) << setiosflags(ios::left) << "number";
    cout << setw(20) << setiosflags(ios::right) << "scientific";
    cout << setw(20) << setiosflags(ios::right) << "signed";
    cout << setw(20) << setiosflags(ios::right) << "precision4" << endl;
//    cout << setiosflags(ios::fixed) << setflags(ios::left) << setprecision(6) << endl; 
//    cout << setiosflags(ios::scientific) << setflags(ios::right)<< endl;
//    cout <<
    cout << setw(20) << fixed << left << setprecision(6) << a ;
    cout << setw(20) << uppercase << scientific << right << a ;
    cout << setw(20) << fixed << showpos << right << a ;
    cout.unsetf(ios::showpos);
    cout << setw(20) << fixed << right << setprecision(4) << a << endl;

    return 0;
}        
