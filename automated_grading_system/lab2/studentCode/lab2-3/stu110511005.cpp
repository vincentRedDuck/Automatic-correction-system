#include<iostream>
#include<iomanip>
using namespace std;

main() 
{
    cout << "Please enter a char : " ;
    char c = 'a';//其實我不知道ASCII是甚麼
    int b;
    cin >> c;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> b;
    
    if ( b == 1)
    {
    cout << c << endl;
    }

    else if ( b == 2)
    {
    cout << (int)c << endl; 
    }

    else if ( b == 3)
    {
    cout << showbase << oct << (int)c << endl;
    }

    else if ( b == 4)
    {
    cout << showbase << hex << (int)c << endl;
    }

    else  
    {
    cout << "No this option." << endl;
    }   
    //到底什麼時候要寫return 0;
    return 0;
}
