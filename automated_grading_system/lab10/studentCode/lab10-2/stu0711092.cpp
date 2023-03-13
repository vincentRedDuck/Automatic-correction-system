#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

struct PoN{
	string  Nb;
	string JN;
	string EN;
        string TN;
	string CN;	
};
struct Pon{
	int Nb;
	string EN;
};
void sort(Pon[],int);
int main(int argc,char *argv[]){

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	ifstream fin2(argv[3]);
	ofstream fout2(argv[4]);
	string ss;
	PoN lN[493];
	int i =0;
	while(getline(fin,ss)){
	stringstream save;
	save << ss;
	save >> lN[i].Nb >> lN[i].JN >> lN[i].EN >> lN[i].TN>> lN[i].CN;	
	fout << lN[i].Nb <<" "<< lN[i].EN <<" "<< lN[i].TN << endl;
	i++;
	}

	string ss2;
	int j = 0;
	Pon f2[1000];
	while(getline(fin2,ss2)){
	stringstream save2;
	save2 << ss2;
	string f1;
	while(save2 >> f1){
	for(int k=0; k < 493;k++){
		if(f1.length()<3){
		int f1i;
		f1i = stoi(f1);
			if(f1i == stoi(lN[k].Nb)){
			f2[j].Nb = stoi(lN[k].Nb);
			f2[j].EN = lN[k].EN;
			}
		}
		else if(f1 == lN[k].Nb ||f1 == lN[k].EN){
			f2[j].Nb = stoi(lN[k].Nb);
			f2[j].EN = lN[k].EN;
	}}
	j++;
	}
	}
	
	sort(f2,j);
	int g = 1;
	Pon mypkg[1000];
	mypkg[0] = f2[0];
	int count =0;
	for(int l=1;l<j;l++){
		for(int m=0;m<l;m++){
			if(f2[m].Nb != f2[l].Nb && m == l-1 ) {mypkg[g] = f2[l]; g++;}
		}
	}

	for(int k = 0;k<g;k++){
	fout2 << mypkg[k].Nb << " "<< mypkg[k].EN << endl;
	}
}

void sort(Pon vec[],int count ){

	for(int i=1;i<count;i++){
		Pon save =vec[i];
		int a = i-1;
		while((a>=0)&&(vec[a].Nb>save.Nb)){
		vec[a+1] = vec[a];
		a--;
		}
		vec[a+1] = save;
	}
}


