#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[]) {
	char *iname = argv[1];
	char *oname = argv[2];
	char ibuf[128];
	char numstr[64];
	
	ifstream in_file;
	ofstream out_file;

	float total = 0;
	float average = 0;
	int count = 0;
	int loc_colon = 0;
	int len_line = 0;

	in_file.open(iname);

	if (in_file.fail()) {
		cout << "File" << iname << " does not exist!" << endl;
		exit(1);
	}

	out_file.open(oname, ios::out);

	cout << "file ok" << endl;

	while (in_file >> ibuf) {
		cout << ibuf << endl;
		len_line = strlen(ibuf);
		loc_colon = strchr(ibuf, ':') - &ibuf[0];
		if (loc_colon < len_line - 1) {
			strncpy(numstr, &ibuf[loc_colon + 1], len_line - loc_colon - 1);
			numstr[len_line - loc_colon - 1] = '\0';
			total += atof(numstr);
		}
		count++;
	}

	average = total / count;

	out_file << "The average is: " << fixed << setprecision(4) << average;

	in_file.close();
	out_file.close();

	return 0;
}


