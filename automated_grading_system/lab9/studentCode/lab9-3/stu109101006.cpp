#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

char decode (string);

char codetable[36][2][10];

int main (int argc, char *argv[]) {
	char *iname = argv[1];
	char *oname = argv[2];
	char *mode = argv[3];

	char ibuf[128];
	char inc;
	char tname[] = "code.txt";
	bool first;

	string buf;
	string input;
	stringstream ss;
	
	ifstream code_table;	
	ifstream in_file;
	ofstream out_file;

	in_file.open(iname);
	out_file.open(oname, ios::out);

	if (in_file.fail()) {
		cout << "File " << iname << " does not exist!" << endl;
		exit(1);
	}

	cout << "============Test File============" << endl;
	cout << "File name: " << iname << endl;
	while (getline(in_file, buf)) {
		cout << buf << endl;
	}
	cout << "============End of File============" << endl;

	in_file.close();

	in_file.open(iname);
	if (in_file.fail()) {
		cout << "File " << iname << " does not exist!" << endl;
		exit(1);
	}

	code_table.open(tname);
	if (code_table.fail()) {
		cout << "File " << tname << " does not exist!" << endl;
		exit(1);
	}
	for (int i = 0; i < 36; i++) {
		code_table >> codetable[i][0][0];
		code_table.get();
		code_table.getline(codetable[i][1], 9);
	}

	cout << mode << endl;
	
	if (strcmp(mode, "e") == 0) {
		cout << "Encoding mode\n";

		while (getline(in_file, buf)) {
			ss.clear();
			ss.str(buf);
			
			first = 1;

			while (ss.get(inc)) {
				
				if (first) first = 0;
				else {
					cout << "   ";
					out_file << "   ";
				}

				if (inc == ' ') {
					cout << "    ";
					out_file << "    ";
				}
				else {
					for (int i = 0; i < 36; i++) {
						if (inc == codetable[i][0][0]) {
							out_file << codetable[i][1];
							cout << codetable[i][1];
						}
					}
				}

			}

			out_file << endl;
			cout << endl;
		}		
	}

	else if (strcmp(mode, "d") == 0) {
		cout << "Decoding mode\n";
		while (getline(in_file, input, '\n')) {
			int cursor = 0;
			int length = input.length();
			int sublen = 0;

			cout << "line: " << input << endl;

			if (input == "") continue;

			while (input.find("   ") != string::npos) {
				/*sublen = input.substr(cursor, length - cursor).find("   ") - cursor;
				cout << sublen << endl; 
				buf = input.substr(cursor, sublen);
				cursor = cursor + sublen + 4;
				cout << "buf: " << buf << endl;
				if (buf == " ") {
					cursor++;
					out_file << " ";
					cout << " ";
				}*/
				length = input.length();
				cursor = input.find("   ");
				buf = input.substr(0, cursor);
				input = input.substr(cursor + 3, length - cursor - 3);

				if (buf == "") {
					input = input.substr(cursor + 1, length - cursor - 1);
					out_file << " ";
					cout << " ";
					continue;
				}			
				
				cout << decode(buf);
				out_file << decode(buf);
			}

			buf = input;

			out_file << decode(buf);
			out_file << endl;
			cout << decode(buf);
			cout << endl;
		}
	}

	in_file.close();
	out_file.close();

	return 0;

}

char decode (string buf) {
	string morse;
	for (int i = 0; i < 36; i++) {
		morse = codetable[i][1];
		if (buf == morse) return codetable[i][0][0];	
	}
	cerr << "\"" << buf << "\" not found\n";
	return '!';
}
