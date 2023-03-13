#include <iostream>
using namespace std;

int main ()

{
    char input;
    int mode;
    cout << "Please enter a char :";
    cin >> input;
    cout << " Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> mode;
    switch (mode)
    {
        case 1:
            cout << input << endl;
        break;
        case 2:
            cout << showbase << (int)input << endl;
        break;
        case 3:
            cout << showbase << oct << (int)input << endl;
        break;
        case 4:
            cout << showbase << hex << (int)input << endl;
        break;
        default:
            cout << "No this option."<<endl ;
        break;
    }
}        
