#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
	
	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);

	double avg; 
	string score = "";
	string text;
	int count =0; int sum=0;
	while(getline(inFile, text)){
		for(int i=0; i<text.length();i++){
			char ch = text[i];
			if(ch == ':'){
				if(i+1 == text.length()){
					score = "0";
				}
				else{
					score = text.substr(i+1, text.length()-i-1);
					break;
				}
			}
			else{
				continue;
			}
		}
		count += 1;			
		sum = sum + stoi(score);
	}
	
	avg = double(sum)/count;
	outFile << "The average is: " << fixed << setprecision(4) << avg ;
	return 0;
}
