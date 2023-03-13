#include <iostream>
#include<iomanip>
#include<bitset>
using namespace std;

int main()
{
    cout<<"Please enter a char : ";
    char ch;
    cin >> ch;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    char num;
    cin >> num;
    switch (num)
    {
        case '1' :
			cout << ch<<endl;
            break;
        case '2' :
            cout << (int)ch<<endl;
            break;
        case '3' :
            cout.setf(ios::showbase);
            cout<<oct<<(int)ch<<endl;
            break;
        case '4' :
            cout.setf(ios::showbase);
            cout<<hex<<(int)ch<<endl;
            break;
        default:
			cout << "No this option."<<endl;
			break;
	}
	return 0;
}
