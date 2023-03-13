#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string space(string);

int main(){

	string sentence;
	cout << "Enter the sentence: ";
	getline(cin,sentence);
	string aa[1000];
	while(sentence != "Stop the program"){
	stringstream save;
	sentence = space(sentence);
	save << sentence;
	int i=0;
	while(save >> aa[i]){
	i++;
	}
	for(int j = i-1;j>=0;j--){
	cout << aa[j] <<" ";
	}
	cout << endl;
	cout << "Enter the sentence: ";
	getline(cin,sentence);
	
	}


}

string space(string sentence){
	
	int max = sentence.length();
	for (int i =0;i<max;i++){
	bool det = isalpha(sentence[i]);
	if (det == 0){
	sentence[i] = ' ';
	}
	}
	return sentence;
}
