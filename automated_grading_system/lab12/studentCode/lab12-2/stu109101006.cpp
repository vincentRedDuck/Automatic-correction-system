#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Student{
	string ID;
	string name;
	int *score;
	int num_score;
	double average;	// top 10 scores average
};


int main (int argc, char *argv[]) {
	// Check for arguments
	if (argc != 2) {
		cerr << "Please check for command format." << endl;
		return(1);
	}

	string filename = argv[1];
	fstream inf;
	stringstream ss;
	string buf;
	struct Student *stulist;

	int nstu = 0;

	inf.open(filename, ios::in);

	// Count number of students
	
	while (getline(inf, buf)) {
		ss << buf << endl;
		nstu++;
	}

	// cout << "Total students: " << nstu;

	// Create student list
	
	stulist = new Student [nstu];

	for (int i = 0; i < nstu; i++) {
		ss >> stulist[i].ID;
		ss >> stulist[i].name;
		ss >> stulist[i].num_score;
		
		stulist[i].score = new int [stulist[i].num_score];
		int *sco_sort = new int [stulist[i].num_score];

		for (int j = 0; j < stulist[i].num_score; j++) {
			ss >> stulist[i].score[j];
			sco_sort[j] = stulist[i].score[j];
		}
		
		sort (sco_sort, sco_sort + stulist[i].num_score, greater<int>());
		
		float total = 0;
		int count = (10 <= stulist[i].num_score ? 10 : stulist[i].num_score);
		for (int j = 0; j < count; j++) {
			 total += sco_sort[j];
		}
		stulist[i].average = total / count;
	}

	// Calculate std deviation
	
	double avg_sum = 0;
	double avg_sqavg = 0;
	double stdev = 0;

	for (int i = 0; i < nstu; i++) {
		avg_sum += stulist[i].average;
		avg_sqavg += (stulist[i].average * stulist[i].average);
	}

	avg_sqavg /= nstu;
	stdev = avg_sqavg - pow(avg_sum/nstu, 2);
	stdev = pow(stdev, 0.5);

	// Print list
	
	for (int i = 0; i < nstu; i++) {
		cout << stulist[i].ID << " "
			<< stulist[i].name << " ";
                	//<< stulist[i].num_score << " ";

                for (int j = 0; j < stulist[i].num_score; j++) {
                          cout << stulist[i].score[j] << " ";
                }

		cout /*<< fixed << setprecision(1)*/ <<stulist[i].average << endl;
	}

	cout << defaultfloat << setprecision(6) << stdev << endl;

	inf.close();

	return 0;
}
