#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double douNum ;
    cout << "Enter a num : ";
    cin >> douNum;
    cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout << left << setw(20) << "number";
    cout << right << setw(20) << "scientific";
    cout << right << setw(20) << "signed";  
    cout << right << setw(20) << "precision4"<<endl;           
    cout << left << setw(20) <<  fixed << setprecision(6) << douNum;
    cout << right << setw(20) <<  scientific << uppercase << douNum;
    cout << right << setw(20) <<  showpos << fixed << setprecision(6) << douNum;
    cout.unsetf(ios :: showpos);
    cout << right << setw(20) << fixed << setprecision(4) << douNum <<endl;
return 0;
}



