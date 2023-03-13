#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Enter message: ";
	string sen; getline(cin, sen);
	int senLen = sen.length();
	int count[123] = {0};
	while(sen!="Stop") {
        senLen = sen.length();
		for(int i=0; i<senLen; i++) {
			int alpha = int(sen[i]);
			count[alpha] += 1; 
		}
	
		for(int i=65; i<=90; i++) {
			if(count[i]!=0) {
				cout << char(i) << ": " << count[i] << endl; 
			}
		}
		for(int i=97; i<=122; i++) {
			if(count[i]!=0) {
				cout << char(i) << ": " << count[i] << endl; 
			}
		}
        cout << "Enter message: ";
        getline(cin, sen);
        for(int i=0; i<123; i++)
            count[i] = 0;
	}

	return 0;
}
