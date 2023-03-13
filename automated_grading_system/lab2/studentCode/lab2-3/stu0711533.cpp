//Program: ex2-3.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char userType;
    int userType1;
    cout << "Please enter a char : ";
    cin >> userType;
    
    int whatType;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> whatType;
    
    if (whatType == 1)
        cout << userType << endl;
    else if (whatType == 2)
       {
        userType1 = int(userType);
        cout << dec << userType1 << endl;
       }
    else if (whatType == 3)
        {
        userType1 = int(userType);
        cout << setiosflags(ios::showbase) << oct << userType1 << endl;
        }
    else if (whatType == 4)
        {
        userType1 = int(userType);
        cout << setiosflags(ios::showbase) << hex << userType1 << endl;
        }
    else
        cout << "No this option." << endl;

    return 0;
}
