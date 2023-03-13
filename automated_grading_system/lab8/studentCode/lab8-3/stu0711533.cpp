#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	cout << "Enter the sentence: ";
	string sen; getline(cin, sen);
	while(sen!="Stop the program") {
		string n_sen = "";
		int senLen = sen.length();
		for(int i=0; i<senLen; i++) {
			if(isalpha(sen[i])) {
				n_sen += sen[i];
			}
			else {
				n_sen += ' ';
			}
		}
        n_sen += ' ';
		string nn_sen = "";
		string volcab = "";
		int space1 = -1;
		for(int i=0; i<n_sen.length(); i++) {
			if(n_sen[i]==' ') {
				for(int j=space1+1; j<i; j++) {
					volcab += n_sen[j];
				}
                if(volcab!="") {
				    nn_sen = ' ' + volcab + nn_sen;
                }
				space1 = i;
				volcab = "";
			}
		} 
        for(int i=1; i<nn_sen.length(); i++)
		    cout << nn_sen[i];
		cout << endl << "Enter the sentence: ";
		getline(cin, sen);
	}
	return 0;
}
