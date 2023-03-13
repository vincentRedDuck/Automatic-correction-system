#include <iostream>
using namespace std;

int main()
{
    int type;
    char input;
    
    cout << "Please enter a char : ";
    cin >> input;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> type;
    switch (type)
    {
    case 1:
        cout << input << endl;
        break;
    case 2:
        cout << int(input) << endl;
        break;
    case 3:
        if (input >= 64)
        cout << "0" << (int(input))/8/8%8 << (int(input))/8%8 << (int(input))%8 << endl;
        else
        cout << "0" << (int(input))/8%8 << (int(input))%8 << endl;
        break;
    case 4:
        cout << "0x" << (int(input)/16%16) << (int(input)%16) << endl;
        break;
    default:
        cout << "No this option." << endl;
        break;
    }
    return 0;
}
