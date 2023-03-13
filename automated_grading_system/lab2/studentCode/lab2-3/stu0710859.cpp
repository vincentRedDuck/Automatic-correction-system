#include<iostream>
using namespace std;

int main(){
    char c;
    int n, out;
    cout << "Please enter a char : ";
    cin >> c;
    out = int(c);
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> n;
    switch (n){
        case 1:
            cout << c << endl;
            break;
        case 2:
            cout << std::showbase << std::dec << out << endl;
            break;
        case 3:
            cout << std::showbase << std::oct << out << endl;
            break;
        case 4:
            cout << std::showbase << std::hex << out << endl;
            break;
        default:
            cout << "No this option." << endl;
            break;
    }
    return 0;
}
