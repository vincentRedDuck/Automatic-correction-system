#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

string str,sna,tok;
char cha;
int pos = 0;
int e = 0;

int main(int argn,char **argv){
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	while(fin.get(cha)){
		pos = 0;
		fout << "=====\n";
		getline(fin,str, ':');
		fin.get(cha);
		fin.get(cha);
		getline(fin,str, '/');
		fout << "Domain name: " << str << endl;
		getline(fin,str, '?');
		for (int i = 0; i < str.length() ; i++){
			if (str[i] == '/')
				pos = i+1;
			
		}
		fout << "Method: " << str.substr(pos,str.length()) << endl;
		e = 0;
		getline(fin,sna);
		sna += '&';
		stringstream ss(sna);
		while (getline(ss,tok,'&')){
			stringstream ss2(tok);
			getline(ss2,str,'=');
			getline(ss2,sna);
			if(sna != "")
				fout << str << ": " << sna << endl;

		}
		
	}
	fout << "=====\n";
	return 0;
}
