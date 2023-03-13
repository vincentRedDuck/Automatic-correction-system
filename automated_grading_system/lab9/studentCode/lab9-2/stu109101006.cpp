#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Stu {
	char name[16];
	int grade[3];
	float avg;
};

int main (int argc, char *argv[]) {
	char *iname = argv[2];
	char oname[128];
	if (argc == 3) {
		strcpy(oname, iname);
		strcat(oname, ".out");
	}
	else if (argc == 4) {
		strcpy(oname, argv[3]);
	}
	else cout << "Check arguments!";

	char ibuf[128];
	int mode = 0;
	int nstu = 0;

	Stu data[128];
	
	ifstream in_file;
	ofstream out_file;

	in_file.open(iname);

	if (in_file.fail()) {
		cout << "File " << iname << " does not exist!" << endl;
		exit(1);
	}

	out_file.open(oname, ios::out);

	strcpy(ibuf, argv[1]);
	mode = atoi(ibuf);

	in_file.get(ibuf, 100);
	nstu = atoi(ibuf);

	for (int i = 0; in_file >> ibuf; i++) {
		strcpy(data[i].name, ibuf);
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			in_file >> data[i].grade[j];
			sum += data[i].grade[j];
		}
		data[i].avg = sum / 3.0;
	}

	bool sorted = 0;

	// sort by average
	if (mode == 1) {
		while (!sorted) {
			sorted = 1;
			for (int i = 0; i < nstu - 1; i++) {
				if (data[i].avg > data[i+1].avg) {
					data[128] = data[i];
					data[i] = data[i+1];
					data[i+1] = data[128];
					sorted = 0;
				}
			}
		}
	}
	
	// sort by name
	if (mode == 2) {
		while (!sorted) {
			sorted = 1;
			for (int i = 0; i < nstu - 1; i++) {
				if (strcmp(data[i].name, data[i+1].name) > 0) {
					data[128] = data[i];
					data[i] = data[i+1];
					data[i+1] = data[128];
					sorted = 0;
				}
			}
		}
	}

	for (int i = 0; i < nstu; i++) {
		out_file << data[i].name << " " 
			<< data[i].grade[0] << " " 
			<< data[i].grade[1] << " " 
			<< data[i].grade[2] << " " 
			<< fixed << setprecision(4) << data[i].avg << endl;
	}

	in_file.close();
	out_file.close();

	return 0;
}


