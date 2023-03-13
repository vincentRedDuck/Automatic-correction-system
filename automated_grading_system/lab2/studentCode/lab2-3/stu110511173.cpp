#include <iostream>
#include <iomanip>
using namespace std;


int main()

{
    char word;
    int num;
    cout << "Please enter a char : ";
    cin >> word;
    
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> num;

    if (num == 1)
        cout << word;
    else if (num == 2)
        cout << showbase << int(word);
    else if (num == 3)  
        cout << "0" << oct <<int(word);
    else if (num == 4)  
        cout << "0x"<< hex << int(word);
    else
        cout<<"No this option.";
    cout<< endl;
    

    return 0;
}
