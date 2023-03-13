#include<iostream>
#include<iomanip>
using namespace std;

int asc(char c){
    return (int)c;
}

int main(){
    char c;
    cout<<"Please enter a char : ";
    cin>>c;

    int otype;
    cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin>>otype;
    switch(otype){
        case 1:
            cout<<c;
            break;
        case 2:
            cout<<(int)c;
            break;
        case 3:
            cout<<std::oct;
            cout<<"0"<<(int)c;
            break;
        case 4:
            cout<<std::hex;
            cout<<"0x"<<(int)c;
            break;
        default:
            cout<<"No this option.";
    }
    cout<<endl;
    return 0;
}
