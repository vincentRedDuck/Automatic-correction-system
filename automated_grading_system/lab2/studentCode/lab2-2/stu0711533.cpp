//Program: ex2-2.cpp
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
    
    cout << left << setw(20) << "number";
    cout.unsetf(ios::left); 
    cout << setw(20) << "scientific";
    cout << setw(20) << "signed";
    cout << setw(20) << "precision4" << endl;
    
    cout << left << setw(20) << fixed << setprecision(6) << num;
    cout.unsetf(ios::left);
    cout << setw(20) << scientific << uppercase << setprecision(6) << num;
    cout << setw(20) << showpos << fixed << setprecision(6) << num;
    cout.unsetf(ios::showpos);   
    cout << setw(20) << fixed << setprecision(4) << num << endl; 



    return 0;
}
