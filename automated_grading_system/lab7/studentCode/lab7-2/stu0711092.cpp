#include<iostream>
#include<string>
using namespace std;




int main(){
	string r;
	cout << "1: encoder 2: decoder 3: quit: ";
	int chose;
	cin >> chose;
	while(chose != 3){
	if(chose == 1|| chose == 2){
		cout << "Please enter sentences length: ";
		int len;
		cin >> len;
		cin >> r ;
		if(chose == 1){
			for(int i=0;i<len;i+=2){
			cout << r[i];
			}
			for(int i=1;i<len;i+=2){
			cout << r[i];
			}
			cout << endl;
		}
		if(chose == 2){
			for(int i=0;i<len/2;i++){
			cout << r[i] << r[i+len/2];
			}
			cout << endl;
		}

	}
	else{
		cout << "invalid input" << endl;
	}

	cout << endl;
	cout << "1: encoder 2: decoder 3: quit: ";
	cin >> chose;

	}




}
