#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;


int main(int argc, char *argv[]) {
	string code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.",
					   "--.", "....", "..", ".---", "-.-", ".-..", "--",
					   "-.", "---", ".--.", "--.-", ".-.", "...",
					   "-", "..-", "...-", ".--", "-..-", "-.--",
					   "--..", "-----", ".----", "..---", "...--", "....-", 
					   ".....", "-....", "--...", "---..", "----."};
	ifstream fin;
	string myfile(argv[1]);
	fin.open(myfile.c_str());
	ofstream fout;
	fout.open(argv[2]);

	string str;
	if(!strcmp(argv[3], "e")) {
		while(getline(fin, str)) {
			for(int i=0; i<str.size(); i++) {
				if(isalnum(str[i])) {
					if(isalpha(str[i]))
						fout << code[int(str[i]-65)];
					else if(isdigit(str[i]))
						fout << code[int(str[i]-48+26)];
					if(i != str.size()-1)
						fout << "   ";
				}
				else
					fout << "    ";
			}
			fout << endl;
			str = "";
		}
	}
	else if(!strcmp(argv[3], "d")) {
		while(getline(fin, str)) {
            str += ' ';
			int i=0; int beg=0;
			while(i < str.size()) {
				string str1;
				if((str[i] == ' ')) {
					str1 = str.substr(beg, i-beg);
					for(int j=0; j<36; j++) {
						if((str1 == code[j]) && (j<26)) {
							fout << char(j+65);
						}
						else if((str1==code[j]) && (j>=26)) {
							fout << j-26;
						}
					}
					if(str[i+3] == ' ') {
						fout << " ";
						i += 7;
						beg = i;
					}
					else {
						i += 3;
						beg = i;
					}
				}
                else i++;
				
			}
			fout << endl;
			str = "";
		}
	}
	fin.close();
	fout.close();
	return 0;
}
