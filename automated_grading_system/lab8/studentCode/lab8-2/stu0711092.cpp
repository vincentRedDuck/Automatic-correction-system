#include<iostream>
#include<string>
using namespace std;

int main(){

	string st;
	cout << "Enter message: ";
	getline(cin, st);
	while(st != "Stop"){
		int max = st.length();

		for (int i =0;i<26;i++){
		int count =0;
			for (int j =0;j<max;j++){
				if(st[j] == char(65+i)){
				count++;
				}
			}

			if(count >0){
			cout << char(65+i) <<": "<< count << endl;
			}	
		}

		for (int i =0;i<26;i++){
		int count =0;
			for (int j =0;j<max;j++){
				if(st[j] == char(97+i)){
				count++;
				}
			}

			if(count >0){
			cout << char(97+i) <<": "<< count << endl;
			}	
		}


		cout << "Enter message: ";
		getline(cin,st);
	}





}
