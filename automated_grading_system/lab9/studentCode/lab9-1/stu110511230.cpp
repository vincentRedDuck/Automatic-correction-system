#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(int argc, char *arg[]){
	ifstream fin;
	ofstream fout;
	int num = 0;
	fin.open(arg[1]);
	char ch = fin.peek();
	int i = 0;
	int p = 0;
	double sum = 0;
	char cha[64];
	while(!fin.eof()){
		if((ch >= '0') && (ch <= '9')){
			fin >> num;
			sum += num;
		}
	        if(ch == ':'){
			i++;
			fin >> cha[p];
			p++;
		} else {
			fin >> cha[p];
			p++;
		}
		ch = fin.peek();
	}
	double k = i;
	double avg = sum/k;
	fout.open(arg[2]);
	fout << fixed << setprecision(4) << "The average is: " << avg;
	fin.close();
	fout.close();
	return 0;

}
