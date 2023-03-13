#include <iostream>
#include <string>
using namespace std;

int main(){

	string str;
	cout << "Enter message: ";
	getline(cin,str);
	while(str!="Stop"){
		int max = str.length();	
		for(int i=0;i<26;i++){
			int count =0;
			for(int j=0;j<max;j++){
				if(str[j]==char(65+i)){
					count +=1;
				}
			}	
			if(count!=0) {
				cout << char(65+i) << ": " << count << endl;
			}
		}
	
		for(int i=0;i<26;i++){
			int count =0;
			for(int j=0;j<max;j++){
				if(str[j]==char(97+i)){
					count +=1;
				}
			}	
			if(count!=0) {
				cout << char(97+i) << ": " << count << endl;
			}
		}


		cout << "Enter message: ";
		getline(cin,str);
	}
	return 0;
}

