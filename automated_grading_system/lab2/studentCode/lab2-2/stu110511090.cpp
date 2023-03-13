//File:ex2-2.cpp
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
   // setprecision() fixed
    cout << left << setw(20)  << "number";
    cout << setw(20) << right << "scientific";
    cout << setw(20) << right << "signed";
    cout << setw(20) << right << "precision4";
    cout << endl;
    cout << fixed << setprecision(6) << left << setw(20) << num;
    cout << uppercase << scientific << setw(20) << right << num ;
    cout << fixed << showpos << setw(20) << right << num ;
    cout << noshowpos << setw(20) << setprecision(4) << right << num ; 
    cout << endl;
    return 0;    
}
