#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char chartype;
    cout <<"Please enter a char : " ;
    cin >> chartype;
    int type;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> type; 
    switch(type)
    { case 1:
     cout << chartype<<endl;
     break;
     case 2:
     cout  << dec <<int(chartype)<<endl;
     break;
     case 3:
     cout << oct <<'0'<<int(chartype)<<endl;
     break;
     case 4:
     cout << hex <<"0x"<<int(chartype)<<endl;
     break;
     default:
     cout << "No this option."<<endl;
}
return 0;
}

