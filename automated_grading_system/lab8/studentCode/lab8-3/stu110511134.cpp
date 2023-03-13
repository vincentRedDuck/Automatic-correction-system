#include <iostream>
#include <cctype>

using namespace std;
const int MAX=100;
string word[MAX];

void parsePrt(string);
//切字 然後都丟到word裡面去 


int main(){
	string setence;
	while(1){
		cout <<"Enter the sentence: ";
		getline(cin,setence);
		if(setence=="Stop the program") break;
		parsePrt(setence);	
		cout<<endl;
		
	}

	return 0;
}

void parsePrt(string line){
	int num = 0;
	string token;
	for(int i=0;i<line.size();i++){
		if(!isalpha(line[i]))continue;
		token += line[i];
		
		if(!isalpha(line[i+1])||(i+1==line.size())){//字切完了(非字母 ex空格) 或是 到行尾了 
			word[num++] = token;
			token.clear();
		}
	}
	for(int i = num-1;i>=0;i--)
		cout <<word[i]<<((i==0)?"\n":" ");
	
}


