//File ex2-3.cpp
#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;
int main (){
       
	char ch; int num; 
	cout <<"Please enter a char : ";
 	cin >> ch; 
        cout <<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
   	cin >>num;
	
	
		if (num==1)
		cout << ch <<endl;
		else if (num==2)
                cout << int(ch) <<endl;
		else if (num==3)
		cout << "0"  << std::oct << int(ch) <<endl;
		else if (num==4)
		cout << "0x" << std::hex << int(ch) <<endl;
	        else 
		cout <<"No this option." <<endl;

                
	return 0;
}

