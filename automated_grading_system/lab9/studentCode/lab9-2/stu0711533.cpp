#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAX = 100;
struct stu {
	string name;
	int scr[3];
	double avg;
};

int main(int argc, char *argv[]) {
	stu student[MAX];
	ifstream fin;
	string myfile(argv[2]);
	fin.open(myfile.c_str());

	string str, str1, str2;
	//getline(fin, str);
	int stuNum;
	// = atoi(str.c_str());
	fin >> stuNum;
	for(int i = 0; i < stuNum; i++){
		fin >> student[i].name >> student[i].scr[0] >> student[i].scr[1] >> student[i].scr[2];
		student[i].avg = (student[i].scr[0] + student[i].scr[1] + student[i].scr[2])/3.0;
	}
	// while(getline(fin, str)) {
	// 	for(int j=0; j<stuNum; j++) {
	// 		for(int i=0; i<str.size(); i++) {
	// 			if(str[i] == ' ') {
	// 				student[j].name = str.substr(0, i-1);
	// 				str1 = str.substr(i+1, str.size());
	// 				break;
	// 			}
	// 		}
	// 		int beg = 0;
	// 		int z = 0;
	// 		double sum = 0.0;
	// 		for(int i=0; i<str1.size(); i++) {
	// 			if(str1[i] == ' ') {
	// 				str2 = str1.substr(beg, i-beg);
	// 				student[j].scr[z++] = atoi(str2.c_str());
	// 				sum += atoi(str2.c_str());
	// 				beg = i;
	// 			}
	// 		}
	// 		student[j].avg = sum/3;
	// 	}

	// }

	if(atoi(argv[1]) == 1) {
		for(int i=stuNum-1; i>=0; i--) {
			for(int j=0; j<=i-1; j++) {
				if(student[j].avg > student[j+1].avg) {
					stu tmp = student[j];
					student[j] = student[j+1];
					student[j+1] = tmp;
				}
			}
		}
	}
	else if(atoi(argv[1]) == 2) {
		for(int i=stuNum-1; i>=0; i--) {
			for(int j=0; j<=i-1; j++) {
				if(student[j].name > student[j+1].name) {
					stu tmp = student[j];
					student[j] = student[j+1];
					student[j+1] = tmp;
				}
			}
		}
	}

	ofstream fout;
	if(argc == 3) {
		fout.open(strcat(argv[2], ".out"));
	}
	else {
		fout.open(argv[3]);
	}
	for(int i =0; i<stuNum; i++) {
		fout << student[i].name << " ";
		for(int j=0; j<3; j++) {
			fout << student[i].scr[j] << " ";
		}
		fout << fixed << setprecision(4) << student[i].avg << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
