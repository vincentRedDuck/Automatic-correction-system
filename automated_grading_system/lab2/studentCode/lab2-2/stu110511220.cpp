#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double num;
    cout <<"Enter a num : " << endl;
    cin >> num;
    cout <<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout <<"number                        scientific              signed          precision4" << endl;
    cout <<left<<setw(20)<< fixed << setprecision(6);
    cout << num ;
    cout <<right<<setw(20)<<scientific<<uppercase<< setprecision(6);
    cout << num ;
    cout <<right<<setw(20)<<fixed<<showpos << setprecision(6);
    cout << num ;
    cout.unsetf(ios :: showpos);
    cout <<right<<setw(20)<<fixed<<setprecision(4);
    cout << num<<endl;
}
