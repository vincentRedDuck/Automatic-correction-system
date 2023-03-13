#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char CHAR;
    int num;
    int num1;
    cout << "Please enter a char : ";
    cin >> CHAR;
    cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    cin >> num;
    if (num==1)
    {   
        cout << CHAR << endl;
    }
    else if (num==2)
    {    
        num1=(int)CHAR;
        cout << dec << showbase;
        cout << num1 << endl;
    }
    else if (num==3)
    {   
        num1=(int)CHAR;
        cout << oct << showbase;
        cout << num1<< endl;
    }
    else if(num==4)
    {   
        num1=(int)CHAR;
        cout << hex << showbase;
        cout << num1<< endl;
    }
    else
    cout << "No this option." << endl;
return 0;   
}
