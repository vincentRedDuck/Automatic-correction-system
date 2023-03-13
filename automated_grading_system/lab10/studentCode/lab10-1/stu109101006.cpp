#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;


int main (int argc, char *argv[]) {
	char *iname = argv[1];
	char *oname = argv[2];

	ifstream in_file;
	ofstream out_file;
	stringstream ss;
	string buf;
	string arg;
	string val;

	in_file.open(iname);

	if (in_file.fail()) {
		cout << "File" << iname << " does not exist!" << endl;
		exit(1);
	}

	out_file.open(oname);

	while (getline(in_file, buf)) {
		ss.clear();
		ss.str(buf);

		out_file << "=====" << endl;
		cout << ss.str() << endl;

		// Domain
		getline(ss, buf, '/');
		ss.ignore(1, '/');
		
		out_file << "Domain name: ";

		for (int i = 0; getline(ss, buf, '/'); i++) {
			if (buf.find("?") == string::npos) {
		       		if (i == 0) out_file << buf;
			}
		}

		out_file << endl;

		ss.clear();
		ss.str(buf);

		// Method
		getline(ss, val, '?');
		out_file << "Method: " << val << endl;

		// Others
		while (true) {
			getline(ss, arg, '=');
			getline(ss, val, '&');
			
			if (val != "") { 
				out_file << arg << ": ";
				out_file << val << endl;
			}
			if (ss.peek() == EOF) break;
		}
	}

	out_file << "=====" << endl;	

	in_file.close();
	out_file.close();

	return 0;
}
