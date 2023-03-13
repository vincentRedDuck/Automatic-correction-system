#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main(){
    char a;
    char b;
    cout<<"Please enter a char : ";
    cin >>a;
    cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >>b;
    switch (b)
{       case '1':
        cout<<a<<endl;
        break;
        case '2':
        cout<<dec<<(int)a<<endl;
        break;
        case '3':
        cout<<"0"<<oct<<(int)a<<endl;
        break;
        case '4':
        cout<<"0x"<<hex<<(int)a<<endl;
        break;
        default:
        cout<<"No this option."<<endl;
}
    return 0;

}
