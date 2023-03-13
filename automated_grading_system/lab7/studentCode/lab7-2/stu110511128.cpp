#include<iostream>
#include<string>
using namespace std;
int main(){int n,m;string s;
	while(1){
	cout <<"1: encoder 2: decoder 3: quit: ";
	cin >> n ;
	if (n==3){break;}
	else if(n!=1&&n!=2&&n!=3){cout <<"invalid input"<< endl;}
	else {cout << "Please enter sentences length: ";
	cin >> m ;
	cin >> s;}
	

	if(n==1){
		
		for(int i=0;i<m;i++){
			if(i%2==0){
			cout << s[i];}
			else{
				continue;}
		}
		for(int i=0;i<m;i++){
			if(i%2!=0){
				cout << s[i];}
			else{
				continue;
			}
		}
		cout << endl;
	}
	else if(n==2){
		for(int i=0;i<m/2;i++){
		cout << s[i] << s[i+m/2];}
		cout << endl;
	
	}
	
	cout << endl;
	
	
	}
return 0;
}
