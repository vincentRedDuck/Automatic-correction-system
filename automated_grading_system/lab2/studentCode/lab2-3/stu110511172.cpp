#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char X;
    cout << "Please enter a char : ";
    cin >> X;
    int type;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> type;
    switch(type){
    case 1:
        cout << X <<endl;
        break;
    case 2:
        cout << dec<<int(X) <<endl;
        break;
    case 3:
        cout << showbase << oct << int(X) << endl;
        break;
    case 4:
        cout << showbase << hex << int(X) << endl;
        break;
    default:
        cout <<"No this option."<< endl;
}}
     
