#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string space(string);
void print(string);

int main(){

	string str;
	cout << "Enter the sentence: ";
	getline(cin, str);
	while(str!="Stop the program"){
		
		string str1 = space(str);
		print(str1);
		cout << endl;

		cout << "Enter the sentence: ";
		getline(cin,str);
	}
	return 0;
}

string space(string str){
	for(int i=0;i<(str.length());i++){
		bool cond = isalpha(str[i]);
		if(cond==0){
			str[i] = ' ';
		}
	}
	return str;
}

void print(string str){
	string array[100];
	stringstream ss;
	ss << str;

	int i=0;
	while(ss >> array[i]){
		i++;
	}
	for(int j=i-1;j>=0;j--){
		cout << array[j] << " ";
	}	

}
