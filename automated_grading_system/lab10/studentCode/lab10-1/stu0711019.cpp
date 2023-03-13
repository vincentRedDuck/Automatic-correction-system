#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv){
	
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	char ch = fin.peek();
	while(!fin.eof()){
		fin.ignore(20,'/');
		fin.ignore(2,'/');
		string domain;
		getline(fin, domain,'/');

		string str1;
		getline(fin,str1,'?');
		int z = str1.rfind('/');
		string method;
		if(z==-1){
			method = str1;
		}
		else{
			method = str1.substr(z+1,str1.length()-z);
		}

		fout << "=====\nDomain name: " << domain << "\nMethod: " << method << endl;
		
		string N,N1,N2;
		getline(fin,N);
		int i=0,j=0,k=0;
		while(i<N.length()){
			j = N.find('=',i);
			k = N.find('&',i);
			if(k!=-1){
				N1 = N.substr(i,j-i);
				N2 = N.substr(j+1,k-j-1);
				
				i = k+1;
				if(N2.compare("") != 0){
					fout << N1 << ": " << N2 << endl;
				}
			}
			else{
				N1 = N.substr(i,j-i);
				N2 = N.substr(j+1,N.length()-j-1);
				i = N.length();
				if(N2.compare("") != 0){
					fout << N1 << ": " << N2 << endl;
				}
			}
			N1.clear();
			N2.clear();
		}
		ch = fin.peek();
	}
	fout << "=====\n";

	return 0;
}
