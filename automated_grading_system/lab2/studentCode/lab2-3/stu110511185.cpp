#include<iostream>
#include<iomanip>
using namespace std;
int main(){
cout<<"Please enter a char : ";
char ipt;
cin >> ipt ;
cout <<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
int che;
cin >> che;
switch (che){
    case 1:
    cout << ipt;
    break;
    case 2:
    cout << int(ipt);
    break;
    case 3:
    cout << oct << showbase << int(ipt);
    break;
    case 4:
    cout << hex << showbase << int(ipt);
    break;
    default:
    cout << "No this option.";
    break;
    }
cout << endl;
}
