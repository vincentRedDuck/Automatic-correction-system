#include <iostream>
#include <iomanip>
using namespace std;
int main(){
char c;
cout << "Please enter a char : ";
cin>>c;
// cout<<endl;
cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
int type;
cin>>type;
switch(type){
    case 1 : cout<<c;break;
    case 2 : cout<<(int)c; break;
    case 3 : cout<<oct<<showbase<<(int)c; break;
    case 4 : cout<<hex<<showbase<<(int)c; break;
    default : cout<<"No this option.";    
}
cout<<endl;
return 0;
}
