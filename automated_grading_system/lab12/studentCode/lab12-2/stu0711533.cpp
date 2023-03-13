#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

struct student {
	string ID;
	string name;
	int *score;
	int num_score;
	double average;
};
double sortAvg(int*, int);
int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	string line; int stuNum = 0;  
	while(getline(fin, line)) { 
		stuNum++; line = "";
	}
	student *data = new student[stuNum];
	fin.close();

	fin.open(argv[1]); int i = 0; double allAvg = 0.0;
	while(getline(fin, line)) {
        stringstream ss(line); 
		ss >> data[i].ID >> data[i].name >> data[i].num_score;
		cout << data[i].ID << " " << data[i].name << " ";

		double total = 0.0;
		data[i].score = new int[data[i].num_score];
		for(int j=0; j<data[i].num_score; j++) {
			ss >> data[i].score[j]; cout << data[i].score[j] << " ";
			total += data[i].score[j];
		}

		if(data[i].num_score >10) data[i].average = sortAvg(data[i].score, data[i].num_score); 
		else data[i].average = total / data[i].num_score;
		cout << data[i].average << endl;
		allAvg += data[i].average;
		i++;
	}

	allAvg = allAvg / stuNum;
    double calStd = 0.0;
    for(int i=0; i<stuNum; i++) {
        calStd += pow((data[i].average - allAvg), 2);
    }
    double stdDev = sqrt(calStd / stuNum); cout << stdDev << endl;
	return 0;
}

double sortAvg(int *score, int num) {
	for(int i=num-1; i>0; i--) {
		for(int j=0; j<=i-1; j++) {
			if(score[j] < score[j+1]) {
				int tmp = score[j+1];
				score[j+1] = score[j];
				score[j] = tmp;
			}
		}
	}
	double avg = 0.0;
	for(int k=0; k<10; k++) {
		avg += score[k];
	}
	return avg/10.0;
}
