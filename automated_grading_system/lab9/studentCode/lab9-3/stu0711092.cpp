#include<iostream> 
#include<fstream> 
#include<string> 
#include<sstream> 
using
namespace std;

struct Morse{ char Engls; 
	string cd; 
}; 
string Encode(char); 
char decode(string&); 
void Output(ifstream &,ofstream &,int); 
Morse mor[36]; 
int main(int argc,char **argv){
	
	ifstream fin ("code.txt");
	for(int i=0;i<36;i++){ 
		fin >> mor[i].Engls >> mor[i].cd; 
	}
	fin.close();	
	ifstream fi(argv[1]); 
	ofstream fout(argv[2]);
	Output(fi,fout,((argv[3][0] =='e')? 1 : 2 ));	
} 
string Encode(char letter){ 
	if(letter == '\n'){ return "\n"; }
	else if(letter == ' '){ 
		return "       "; }
	else{ 
		for(int i=0;i<36;i++){
			if(letter == mor[i].Engls)return mor[i].cd +' '; } 
	} 
	return "\0"; 
}
char decode(string &code){ 
	for(int i=0;i<36;i++){ 
		if(code == mor[i].cd){ 
			code.clear(); 
			return mor[i].Engls; } 
	} 
	return ' ' ; 
} 
void Output(ifstream &fin,ofstream &fout,int opt){
	
	char letter; 
	if(opt == 1){ 
		while(fin.get(letter)){ 
			Encode(letter); 
			fout << Encode(letter); } 
	}else{ 
		string save; 
		int num = 0;	
		while(fin.get(letter)){ 
			if(letter =='.'||letter =='-'){
				save += letter; num =0; 
			}else if(letter =='\n'){ 
				fout << decode(save) <<endl; 
			}else{ 
				num++;
			       if(num == 3){
			       	fout << decode(save);
			       }	
			       if(num == 7){
			       	fout << ' ';
			       }
			}
		}
	}
}

