#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double num;
    cout << "Enter a num : ";
    cin >> num;
    cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
    cout << left << setw(20) << "number" ;
    cout << right << setw(20) << "scientific";
    cout << right << setw(20) << "signed";
    cout << right << setw(20) << "precision4";
    cout << endl;
    cout << left << setw(20) << fixed << setprecision(6) << num;
    cout << right << setw(20) << uppercase << scientific << setprecision(6) << num;
    cout << right << setw(20) << fixed << showpos << num;
    cout << right << setw(20) << defaultfloat << noshowpos << fixed  <<  setprecision(4) << num << "\n";


}
