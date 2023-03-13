#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a;
    cout << "Enter a num : ";
    cin  >> a;
    cout <<"\n";
    cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" <<endl;
    cout << left << setw(14)<< "number" << right << setw(26)<<"scientific" <<setw(20)<<"signed"<<setw(20)<<"precision4"<<endl;
    cout << fixed << setprecision(6) << left << setw(14)  << a ;
    cout << right << setw(26)<<uppercase<< scientific << a;//all is from  right 
    cout <<showpos<<fixed << setprecision(6)<< setw(20) << a;
    cout <<noshowpos<< setw(20) << fixed << setprecision(4) << a <<endl;
    return 0;
}
