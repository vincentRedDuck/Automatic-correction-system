#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double num;
    cout <<  "Enter a num : ";
    cin >> num;
    cout << "\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;
    cout << "number                        scientific              signed          precision4" << endl;
    cout<<left<<setw(20) <<fixed<<setprecision(6)<<num;
    cout<<right << setw(20); cout<<right<<uppercase<<scientific<< num;
    cout<<right<< setw(20); cout<<right<<showpos<<fixed << num;
    cout.unsetf(ios::showpos);
    cout <<right<< setw(20); cout<< right<<setprecision(4)<<num<< endl;


    return 0;
}
