#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char a;
    cout << "Please enter a char : ";
    cin >> a;
    
    int b;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> b;

    if(b == 1){
        cout << a<<endl;    
    }else if(b == 2){
        b = a ;
        cout << b << endl;
    }else if(b == 3){
        b = a;
        cout << oct <<"0"<<  b << endl;
    }else if(b==4){
        b = a;
        cout << hex <<"0x"<< b << endl;
    }else {
        cout << "No this option."<<endl;
    }

return 0;
}
