#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char Char;
    int Choice;
    cout << "Please enter a char : ";
    cin >> Char;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> Choice;
    
    switch(Choice){
        case 1: 
            cout << Char << endl;
            break;
        case 2: 
            cout << std::dec << int(Char) << endl;
            break;
        case 3: 
            cout << std::oct << setw(3) << showbase << int(Char) << endl;
            break;
        case 4: 
            cout << std::hex << std::showbase << int(Char) << endl;
            break;
        default:
            cout << "No this option." << endl;
            break;
    } 
    
    return 0;
}
