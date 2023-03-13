#include <iostream>
#include <string>
using namespace std;

string str;

int main () {
	cout << "Enter message: ";
	getline(cin,str);
	while (str != "Stop"){
		for (int i = 0;i < 58;i++){
			int count = 0;
			int c = 0;
			while (str[c] != '\0'){
				if (str[c] == char('A'+i))
					count++;
				c++;
			}
			if (count != 0)
				cout << char('A'+i) << ": " << count << endl;
		}
		cout << "Enter message: ";
		getline(cin,str);
	}
	return 0;
}
