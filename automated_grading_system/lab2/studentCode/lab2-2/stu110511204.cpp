#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num;
    cout << "Enter a num : ";
    cin >> num;
    cout << endl;
    cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout << setw(20) << left << "number";
    cout << setw(20) << right << "scientific";
    cout << setw(20) << right << "signed";
    cout << setw(20) << right << "precision4" << endl;

    cout << setprecision(6) << fixed << setw(20) << left << num;
    cout << setw(20) << right << setprecision(6) << scientific << uppercase << num;
    std :: cout.unsetf(std::ios::scientific);
    cout << setw(20) << right << fixed << setprecision(6) << showpos << num;
    std :: cout.unsetf(std::ios::showpos);
    cout << setw(20) << right << fixed << setprecision(4) << num << endl;

    return 0;
}