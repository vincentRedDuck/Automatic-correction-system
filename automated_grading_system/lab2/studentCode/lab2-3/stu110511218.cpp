#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
cout<<"Please enter a char : ";
char asc;
int sel,num;
cin>>asc;
num=asc;
cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
cin>>sel;
switch(sel)
{
    case 1:
    cout<<asc;
    break;
    case 2:
    cout<<setw(2)<<num;
    break;
    case 3:
    cout<<setw(3)<<showbase<< oct<<num;
    break;
    case 4:
    cout<<setw(4)<<showbase<<hex<<num;
    break;
    default:
    cout<<"No this option.";
}
cout<<endl;
}

