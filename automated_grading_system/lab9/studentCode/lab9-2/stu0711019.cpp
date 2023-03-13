#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct Score{
	string name;
	int s1;
	int s2;
	int s3;
	double avg;
};
const int MAX=20;
void Sort(Score [], int, int);
bool bigger(Score, Score, int);

int main(int argc, char **argv){
	Score N[MAX];
	int num = atoi(argv[1]);
	ifstream inFile(argv[2]);
	string ofname = (argc ==4)? string(argv[3]):(string(argv[2])+".out");
	ofstream outFile(ofname);

	string stuNum;
	getline(inFile,stuNum);
	int stuN = stoi(stuNum);
	string oneline;
	for(int i=0; i<stuN; i++){
		getline(inFile,oneline);
		stringstream ss;
		ss << oneline;
		ss >> N[i].name >> N[i].s1 >> N[i].s2 >> N[i].s3;
		N[i].avg = (N[i].s1+N[i].s2+N[i].s3)/3.0;
	}
	Sort(N, stuN, num);
	for(int i=0; i<stuN; i++){
		outFile <<  N[i].name << fixed << setprecision(4) << " " << N[i].s1 << " " << N[i].s2 << " " << N[i].s3 << " " << N[i].avg << endl;
	}
}

void Sort(Score vec[], int len, int n){
	for(int j=1;j<len;j++){                                 // compare from second card to the last one
		Score key=vec[j];                               // set the 'current' card as key
		int i = j-1;                                    // compare the card before the 'current' one
		while ((i>=0)&&(bigger(vec[i], key, n))){
			vec[i+1] = vec[i];
			i--;
		}
		vec[i+1] = key;
	}
}

bool bigger(Score x, Score y, int n){
	return ((n==2)?(x.name>y.name):(x.avg>y.avg));
}
