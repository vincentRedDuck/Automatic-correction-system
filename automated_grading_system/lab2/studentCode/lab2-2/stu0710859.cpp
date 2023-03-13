#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double n, n1;
    int e = 0 , n2;
    cout << "Enter a num : " << endl;
    cin  >> n ;
    cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout << "number" << setw(34) << "scientific" << setw(20) << "signed" << setw(20) <<"precision4" << endl;
    cout << setw(26) << left << fixed << setprecision(6) << n  ;
    cout << fixed << setw(14) << right << setprecision(6) << std::scientific << std::uppercase << n << setw(20);
    std::cout.unsetf(std::ios::scientific);
    cout << std::showpos << fixed << setprecision(6) << n << setw(20);
    cout << fixed << setprecision(4) << noshowpos << n << endl;

    return 0;
}
