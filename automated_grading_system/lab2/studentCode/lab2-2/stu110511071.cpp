#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    double num;
    cout << "Enter a num :";
    cin >> num;
    cout << endl <<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;

   cout << left << setw(30) << "number"
        << left << setw(24) << "scientific"
        << left << setw(16) << "signed" 
        << "precision4" << endl;
    cout << left << setw(20) << fixed << setprecision(6) << num;
    cout << right << setw(20) << fixed << uppercase << scientific << num;
    cout. unsetf(ios::scientific);
    cout << right << setw(20) << fixed << setprecision(6)<<showpos <<num << noshowpos;
    cout << right << setw(20) << fixed << setprecision(4) << num << endl;



    return 0;
}
