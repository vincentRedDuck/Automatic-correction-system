#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main( int argc, char* argv[]){

	string name[1000] = {""};
	bool res[1000] = {0};
	int ans[1000] = {0};
	int count = 0;

	ifstream infile1, infile2;
	ofstream outfile1, outfile2;

	infile1.open(argv[1]);
	infile2.open(argv[3]);

	outfile1.open(argv[2]);
	outfile2.open(argv[4]);
	string str;

	while(getline(infile1, str)){
		stringstream ss(str);
		string num, en, ch;
		ss >> num >> en >> en >> ch;
		name[stoi(num)] = en;
		outfile1 << num << " " << en << " " << ch << endl;
		
	}
	infile1.close();
	outfile1.close();

	while(infile2 >> str){
		
		if(isdigit(str[0])){
			//cout << "digit" << str;
			if(!res[stoi(str)]){
				// cout << " | " << name[stoi(str)] << endl;
				res[stoi(str)] = true;
			       	ans[count] = stoi(str);
				count += 1;	
			}
			else continue;
		}
		else{
			int i = 0;
			for(i; i < 1000; i++){
				if(str == name[i]){
					break;
				}	
			}

			if(!res[i]){
				// cout << i-1 << " | " << str << endl;
				res[i] = true;
				ans[count] = i;
				count += 1;
			}
		}
		// cout << "This: " << str << endl;
		str.clear();
	}
	std::sort(ans, ans+count);
	for(int i = 0; i < count; i++){
	
		outfile2 << ans[i] << " " << name[ans[i]] << endl;
		cout << ans[i] << " " << name[ans[i]] << endl;
	}



	return 0;
}

