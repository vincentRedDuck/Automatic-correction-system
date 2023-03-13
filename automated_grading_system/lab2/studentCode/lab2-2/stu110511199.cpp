//File: ex2-2.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a;
    cout << "Enter a num : " << '\n';
    cin >> a ;

    cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;

    cout << left << setw(20) << "number" << right << setw(20) << "scientific" << right << setw(20) << "signed" << right << setw(20) << "precision4" <<'\n';

    cout << left << setw(20) << fixed << setprecision(6) << a << right << setw(20) << uppercase << scientific << setprecision(6) << a << fixed << right << setw(20) << showpos << setprecision(6) << a << fixed << noshowpos << right << setw(20) << fixed << setprecision(4) << a << '\n';
        
    return 0;
}
