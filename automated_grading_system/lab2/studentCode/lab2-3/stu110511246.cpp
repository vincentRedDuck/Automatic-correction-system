#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a;
    char x;
    cout<<"Please enter a char : ";
    cin>>x;
    cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin>>a;
    if(a==1)
        cout<<x<<endl;
    else if(a==2)
        cout<<int(x)<<endl;
    else if(a==3)
        cout<<"0"<<oct<<int(x)<<endl;
    else if(a==4)
        cout<<"0x"<<hex<<int(x)<<endl;
    else 
        cout<<"No this option."<<endl;
    return 0;
}
