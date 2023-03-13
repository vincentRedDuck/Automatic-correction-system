#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num = 0;
    cout << "Enter a num : ";
    cin >> num;
    
    cout << "\n\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
    cout << left << setw(20) << "number";
    cout.unsetf(ios::left);
    cout << setw(20) << "scientific" << setw(20) << "signed" << setw(20) << "precision4" << endl;

    cout << left << fixed << setw(20) << double(num);
    cout.unsetf(ios::left);
    cout.unsetf(ios::fixed);

    cout << setiosflags(ios::scientific) << uppercase << setw(20) << num;
    cout.unsetf(ios_base::floatfield);

    cout << fixed << showpos << setw(20) << num;

    cout << noshowpos << setprecision(4) << setw(20) << num << endl;

    return 0;
}
