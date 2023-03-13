#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string str;
string tstr[100];
int s = 0;

int main (){
	cout << "Enter the sentence: ";
	getline(cin,str);
	while (str != "Stop the program"){
		int s = 0;
		int o = 0;
		for(int i = 0;i < str.length();i++){
			if(((i > 1) && (!(isalpha(str[i-1])))) && (!(isalpha(str[i])))){
				s++;
				continue;
			}
			if(!(isalpha(str[i]))){
				tstr[o] = str.substr(s,(i-s));
				s = i+1;
				o++;
				//cout << tstr[o-1];
				//cout << " :" << o-1 << endl;	
			}	
		}
		cout << str.substr(s,(str.length())) << " ";
		for (int i = o-1; i >= 0;i--){
			//cout << "i: " << i << " " ;
			string end =  ((i==o)?"\n":" ");
			cout << tstr[i] << end; 
		}
		cout << endl;
	        cout << "Enter the sentence: ";
        	getline(cin,str);
	}
	return 0;
}
