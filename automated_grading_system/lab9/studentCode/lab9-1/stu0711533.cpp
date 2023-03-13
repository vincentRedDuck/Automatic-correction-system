#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin;
	string myfile(argv[1]);
	fin.open(myfile.c_str());

	int num = 0;
	double sum=0.0;
	string str, str1;
	while(getline(fin, str)) {
		for(int i=0; i<str.size(); i++) {
			if(str[i] == ':') {
				str1 = str.substr(i+1, str.size()-i-1);
				if(str1 != "")
					sum += atoi(str1.c_str()); 
				num++;
			}
		}
	}
	double avg = sum/num;
	ofstream fout;
	fout.open(argv[2]);
	fout << "The average is: " << fixed << setprecision(4) << avg;

	fin.close();
	fout.close();
	return 0;
}
