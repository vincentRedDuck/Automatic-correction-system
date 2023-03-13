//File ex2-3.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
using std::oct;
using std::hex;
int main()
{
    char a;
    int type;
    cout << "Please enter a char : " ;
    cin >> a ;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : " ;
    cin >> type ;
    switch (type)
    {
        case 1:
            cout << a << endl;
            break;
        case 2:
            cout << int(a) << endl;
            break; 
        case 3:
            cout << "0" << oct << int(a) << endl;
            break;
        case 4:
            cout << uppercase << "0x" << hex << int(a) << endl;
            break;
        default:
            cout << "No this option." << endl;
            break;
    }    
    return 0;
}
