//File: ex2-3.cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char sym;
    int typ;
    cout << "Please enter a char : ";
    cin >> sym;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> typ;
    switch (typ)
    {
        case 1:
            cout << sym;
            break;
        case 2:
            cout << dec << showbase << (int)sym;
            break;
        case 3:
            cout << oct << showbase << (int)sym;
            break;
        case 4:
            cout << showbase << hex;
            cout << (int)sym;
            break;
        default:
            cout << "No this option.";
            break;
    }
    cout << endl;
    return 0;
}
