#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct Score{
	string Name;
	int S[3];
	double result;
};

bool Big(Score,Score,int);
void RE1(Score[],int,int);
const int Max = 100; 

int main(int argc,char *argv[]){
	
	Score real[Max];
	int opt = atoi(argv[1]);
	ifstream Fin(argv[2]);
	string filename = ((argc == 4 )?argv[3]:(string(argv[2])+".out") );
	ofstream Fout(filename);
	
	int number; Fin >> number;
	for(int i =0;i<number;i++){
	
	Fin >> real[i].Name >> real[i].S[0] >> real[i].S[1] >> real[i].S[2];
	real[i].result = (real[i].S[0]+real[i].S[1]+real[i].S[2])/3.0;	
	}
	RE1(real,number,opt);

	for(int i=0;i<number;i++){
		
	Fout << real[i].Name <<" " <<real[i].S[0] << " "<< real[i].S[1] << " "
		<< real[i].S[2] <<" "<< fixed << setprecision(4) << real[i].result<<endl;

	}	

}

bool Big(Score x, Score y,int opt){

	return ((opt == 1)?(x.result>y.result):(x.Name>y.Name));
}

void RE1(Score whole[],int count,int opt){
	Score Key;
	for(int i=1;i<count;i++){
		Key = whole[i];
		int j =i-1;
		while(j>=0 && Big(whole[j],Key,opt)){
		whole[j+1] = whole[j]; 
		j--;
		}
		whole[j+1] = Key; 
	}
}



