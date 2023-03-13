#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

struct POKEMON{
	string id;
	string en, tn;
};

POKEMON pdex[500],mypk[500];//dictionary,package
int searchPKM(POKEMON[],int,string);
void insertSort(POKEMON[], int);

int main(int argc,char** argv){
	
	ifstream fin(argv[1]);
	ofstream fot(argv[2]);
	
	string line, tok;
	int num = 0;
	
	while(getline(fin,line)){
		stringstream ss(line);
		ss >>pdex[num].id >> tok >>pdex[num].en >>pdex[num].tn;
		fot <<pdex[num].id<<" "<<pdex[num].en <<" "<<pdex[num++].tn<<endl;
	}
	fin.close();fot.close();
	
    fin.clear();fot.clear();// add by me
	fin.open(argv[3]);
	fot.open(argv[4]);
	
    int cnt = 0;
	tok.clear();
    while(fin >> tok){
		int id =(isdigit(tok[0]) ? atoi(tok.c_str()): searchPKM(pdex , num, tok));
		if(searchPKM(mypk, cnt, pdex[id-1].en)==-1){
			mypk[cnt].id = pdex[id-1].id;
			mypk[cnt++].en = pdex[id-1].en;
		}
	}
	
	insertSort(mypk, cnt);
	for(int i =0;i<cnt; i++){//這邊輸出的是數字 ex.1 不是001
		fot <<atoi((mypk[i].id).c_str())<<" "<<mypk[i].en<<endl;
	} 
	fin.close();fot.close();
	return 0;
}

int searchPKM(POKEMON vec[], int num, string en){
	for(int i =0;i<num; i++){
		if (vec[i].en==en) 
            return atoi((vec[i].id).c_str());
	}
	return -1;
}
void insertSort(POKEMON vec[], int len){
	for(int j=1; j<len; j++){
		POKEMON key(vec[j]);
		int i=j-1;
		while((i>=0)&&((vec[i].id>key.id))){
			vec[i+1] = vec[i];
			i--;
		}
		vec[i+1] = key;
	}
}
