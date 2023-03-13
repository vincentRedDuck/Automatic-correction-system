#include <iostream>
#include <cmath>
using namespace std;

void encoder(int len,char s[]);
void decoder(int len,char s[]);
int main(){
	int coder;
	int len, MAX=500;
	char s[MAX];
	cout << "1: encoder 2: decoder 3: quit: " ;
	cin >> coder;
	while(coder!=3){
		if(coder!=1 && coder!=2){
			cout << "invalid input\n" << endl;
		}
		else{
			cout << "Please enter sentences length: ";
			cin >> len;
			for(int i=0;i<len;i++){
				cin >> s[i];
			}
			if(coder==1){
				encoder(len,s);
				cout << "\n\n";
			}
			if(coder==2){
				decoder(len,s);
				cout << "\n\n";
			}
		}
		cout << "1: encoder 2: decoder 3: quit: ";
		cin >> coder;
	}
	return 0;
}

void encoder(int len, char s[]){
	int n;
	n = (len%2==0)?(len/2):((len+1)/2);
	for(int i=0;i<n;i++){
		cout << s[2*i]; 
	}

	for(int i=0;i<n-1;i++){
		cout << s[2*i+1];
	}
	if (len%2==0){
		cout << s[2*n-1];
	}
}
void decoder(int len,char s[]){
	int n1 = int(ceil(len/2.0));
	int n2 = int(floor(len/2.0));
	for(int i=0; i<n1;i++){
		cout << s[i] << ((i<n2)? s[i+n1]:'\0');
	}	
}
