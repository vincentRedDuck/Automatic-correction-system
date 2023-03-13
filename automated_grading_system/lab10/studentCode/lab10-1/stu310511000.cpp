#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){


	ifstream infile;
	ofstream outfile;
	infile.open(argv[1]);
	outfile.open(argv[2]);
	string str;
	while(getline(infile, str)){
	
		outfile << "=====" << endl;
		
		//cout << str << endl;
		str.erase(0, str.find("//") + 2);
		//cout << str << endl;
		string tmp = str;
		tmp.erase(tmp.find('/'));
		outfile << "Domain name: " << tmp << endl;
		while(str.find('/') != string::npos){
			str.erase(0, str.find('/') + 1);
		}
		tmp = str;
		tmp.erase(tmp.find('?'));
		outfile << "Method: " << tmp << endl;
		
		str.erase(0, str.find('?')+1);
		while(str.find('=') != string:: npos){
			tmp = str;
			if(str.find('&') != string::npos){
				tmp.erase(tmp.find('&'));
			}
			string tmp2 = tmp;
			if( tmp.erase(0, tmp.find('=') + 1) != ""){
				outfile << tmp2.erase(tmp2.find('=')) << ": " << tmp.erase(0, tmp.find('=') + 1) << endl;
			}
			if(str.find('&') != string::npos){
				str.erase(0, str.find('&') + 1);
			}
			else{
				break;
			}
			//cout << str << endl;
		}
	}

	outfile << "=====" << endl;

	infile.close();
	outfile.close();



}
