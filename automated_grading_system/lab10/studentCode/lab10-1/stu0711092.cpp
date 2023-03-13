#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;


int main(int argc, char *argv[]){

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	string ss;
	char ch = fin.peek(); 
	while(getline(fin,ss)){
		stringstream save;
		save << ss;
		fout << "=====" << endl;
		string domain;
		for(int i = 0 ; i<3; i++){
		getline(save,domain,'/');
		}
		fout << "Domain name: " << domain << endl;

		stringstream save2;
		string method;
		getline(save,method,'?');
		save2 << method;
		while(getline(save2,method,'/')){
		}	
		fout << "Method: " << method << endl;

		string vary;
		while(getline(save,vary,'&')){
			stringstream name;
			name << vary;
			string na;
			string re;
			getline(name,na,'=');
			getline(name,re);
			if(re != ""){
			fout << na <<": " ;
			fout << re << endl;}
		}
		
		
		}
	
	fout << "====="<< endl;

}

