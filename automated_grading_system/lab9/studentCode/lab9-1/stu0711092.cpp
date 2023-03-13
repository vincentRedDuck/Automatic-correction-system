#include<iostream>
#include<fstream>
#include<cstdio>
#include<iomanip>
using namespace std;

int cal(string); 

int main(int argc, char *argv[]){
	ifstream Fin(argv[1]);
	ofstream Fout(argv[2]);
	string line;
	double nu =0.0;
	int count = 0;
	while(getline(Fin,line)){
	cal(line);
	nu +=cal(line);
	count++;
	}
	Fout << "The average is: "<<fixed << setprecision(4) << double(nu/count);
}

int cal(string line){
	char ch,th;
	string line1 =line;
	int count=0;
	int coun =0;
	for(int i=0;i<line.length();i++){
	count++;
	if(line[i] == ':') break;
	}
	for(int i=0;i<line.length();i++){
	if(th == '\n')break;
	coun++;
	}
	if((coun-count)==0) return 0; 
	else {return stoi(line.substr(count,coun-count));};
}


