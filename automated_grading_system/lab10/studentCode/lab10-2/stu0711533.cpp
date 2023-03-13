#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
struct myPok {
	int numMy;
	string name;
};
struct Pok{
	int no;
	string enName;
};
int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	Pok allPok[493]; int i=0;
	string line;
	while(getline(fin, line)) {
		istringstream sin(line);
		int num; 
		string jp, en, tw, ch;
		sin >> num >> jp >> en >> tw >> ch;

		ostringstream sout;
		sout << setw(3) << setfill('0') << num << " " << en << " " << tw;
		string sorted = sout.str();
		fout << sorted << endl;

		allPok[i].no = num; allPok[i].enName = en;
		i++;
	}
	fin.close();
	fout.close();

	fin.open(argv[3]);
	fout.open(argv[4]);
	string sent; int number, j=0;
	myPok myFile[500]; bool copy = true;
	while(getline(fin, sent)) {
		stringstream ss(sent);
		string str;
		while(ss >> str) {
			if(isdigit(str[0])) {
				number = atoi(str.c_str());
                for(int z=0; z<j; z++){
                    if(number == myFile[z].numMy) {
                        copy = false;
                        break;
                    }
                }
                if(copy) {
				    myFile[j].numMy = number;
				    myFile[j].name = allPok[number-1].enName;
				    j++;
                }
			}
			else {
				for(int i=0; i<493; i++) {
					if(str == allPok[i].enName) {
                        for(int z=0; z<j; z++) {
                            if(str == myFile[z].name) {
                                copy = false;
                                break;
                            }
                        }
                        if(copy) {
						    myFile[j].numMy = i+1;
						    myFile[j].name = allPok[i].enName;
						    j++;
                        }
					}
				}
			}
            copy = true;
		}
	}
	for(int i=0; i<j-1; i++) {
		for(int k=0; k<j-i-1; k++) {
			if(myFile[k].numMy > myFile[k+1].numMy) {
				myPok tmp = myFile[k];
				myFile[k] = myFile[k+1];
				myFile[k+1] = tmp;
			}
		}
	}
	for(int i=0; i<j; i++) {
		fout << myFile[i].numMy << " " << myFile[i].name << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
