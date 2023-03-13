#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

struct Pokedex {
	int n;
	string name_en;
	string name_tc;
};

int main (int argc, char *argv[]) {
	char *foriPkdN = argv[1];
	char *fnPkdN = argv[2];
	char *fiMyPokN = argv[3];
	char *foMyPokN = argv[4];

	ifstream foriPkd;
	ifstream fiMyPok;
	ofstream fnPkd;
	ofstream foMyPok;
	stringstream ss;
	string buf;

	Pokedex nPkd [1024];
	Pokedex myPok [1024] = {};

	bool myPokChk [1024] = {};

	// Open files

	foriPkd.open(foriPkdN);

	if (foriPkd.fail()) {
		cout << "File" << foriPkdN << " does not exist!" << endl;
		exit(1);
	}


	fiMyPok.open(fiMyPokN);

	if (fiMyPok.fail()) {
		cout << "File" << fiMyPokN << " does not exist!" << endl;
		exit(1);
	}

	fnPkd.open(fnPkdN, ios::out);
	foMyPok.open(foMyPokN, ios::out);


	// Build new Pokedex
	
	for (int i = 0; foriPkd >> buf; i++) {
		cout << buf << endl;
		nPkd[i].n = stoi(buf);
		foriPkd >> buf;
		foriPkd >> nPkd[i].name_en;
		foriPkd >> nPkd[i].name_tc;
		cout << nPkd[i].name_tc<<endl; 
		if (isalpha(nPkd[i].name_tc[0])){	
			nPkd[i].name_en += (" " + nPkd[i].name_tc);
			foriPkd >> nPkd[i].name_tc;
			cout << "change " << nPkd[i].name_tc<<endl;
		}
		foriPkd >> buf;
	}


	// Write new Pokedex to file	

	for (int i = 0; i == 0 ? 1 : nPkd[i].n == nPkd[i-1].n + 1; i++) {
		fnPkd << setw(3) << setfill('0') << nPkd[i].n; 
		fnPkd << " " << nPkd[i].name_en << " " << nPkd[i].name_tc << endl;
	}

	// Add MyPokemon
	
	while (fiMyPok >> buf) {

		//  --Search by number

		if (isdigit(buf[0])) {
			myPokChk[atoi(buf.c_str()) - 1] = 1;
		}

		else if (isalpha(buf[0])) {
			bool found = 0;
			
			for (int i = 0; i < 1024; i++) {
				if (buf ==  nPkd[i].name_en) {
					myPokChk[i] = 1;
					found = 1;
				}

			}

			if (!found) {
				for (int i = 0; i < 1024; i++) {
					if (nPkd[i].name_en.find(buf) != string::npos) {
					      	myPokChk[i] = 1;
						break;
					}
				}
			}
		}	
	}


	// Build new MyPokemon list
	
	int len_myPok = 0;
	for (int i = 0; i < 1024; i++) {
		if (myPokChk[i]) {
			myPok[len_myPok] = nPkd[i];
			len_myPok++;
		}
	}


	// Output new list to file
	
	for (int i = 0; i < len_myPok; i++) {
		foMyPok << myPok[i].n << " " << myPok[i].name_en << endl;
	}

	
	// Close files

	foriPkd.close();
	fnPkd.close();
	fiMyPok.close();
	foMyPok.close();


	return 0;
}
