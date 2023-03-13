#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a;
    cout << "Enter a num : ";
    cin >> a;
    cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<< endl;

    cout << left << setw(20) << "number";
    cout << right  << setw(20) << "scientific";
    cout << right << setw(20) << "signed";
    cout << right << setw(20) << "precision4"<< endl;
    
    cout << left << setw(20) << fixed << setprecision(6) << a;
    cout << right << setw(20) << uppercase << scientific  << a;
    cout << right << setw(20) << fixed << showpos << a;
    cout.unsetf(ios :: showpos);
    cout << right << setw(20) << fixed << setprecision(4) << a << endl;

return 0;
}
