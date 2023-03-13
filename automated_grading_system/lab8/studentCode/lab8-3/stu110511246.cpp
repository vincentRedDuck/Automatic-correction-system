#include<sstream>
#include<iostream>
#include<string>
using namespace std;
int main() {
	while(1) {
		cout<<"Enter the sentence: ";
        stringstream ss;
		string str1,tem,str2[100000];
		getline(cin,str1);
		int j=0;
		if(str1=="Stop the program") {
			break;
		}
		int l=str1.length();
		for(int i=0; i<l; i++) {
			if((int(str1[i])>=65&&int(str1[i])<=90)||(int(str1[i])>=97&&int(str1[i])<=122)) {
				//do nothing
			} else {
				str1[i]=' ';
			}
		}
		ss<<str1;
		while(ss>>tem) {
			str2[j]=tem;
			j++;
		}
		for(int k=j-1; k>=0; k--) {
			if(k!=0)
				cout<<str2[k]<<" ";
			else
				cout<<str2[k];
		}
		cout<<endl;
	}
	return 0;
}

