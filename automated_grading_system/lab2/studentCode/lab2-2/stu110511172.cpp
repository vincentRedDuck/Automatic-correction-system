#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double num;
    
    cout << "Enter a num : ";
    cin >> num;
    cout <<endl<< "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;
    cout <<       "number                        scientific              signed          precision4"<<endl;
    cout << fixed << setprecision(6);
    cout << left <<setw(20) << num ;
    cout << right << uppercase << setw(20)<< scientific << num ;
    cout << setw(20)<<fixed<< showpos << num ;
    cout << fixed <<setprecision(4);
    cout << noshowpos<<setw(20)<< num <<endl;

}
