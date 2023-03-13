#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int const MAX=1000;
struct POK{
	string num;
	string jp;
	string en;
	string ch;
	string cch;
};
struct MYPOK{
	int NUM;
	string EN;
};
void Sort(MYPOK[], int);
bool repeat(MYPOK[], int);
int main(int argc, char *argv[]){

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	ifstream fmin(argv[3]);
	ofstream fmout(argv[4]);
	string oneline;
	POK index[MAX];
	MYPOK MY[MAX];
	int i=0;
	while(getline(fin,oneline)){
		stringstream ss;
		ss << oneline;
		ss >> index[i].num >> index[i].jp >> index[i].en >> index[i].ch >> index[i].cch;
		fout << index[i].num << " " << index[i].en << " " << index[i].ch << endl;
		i++;
	}
	string my;
	int j=0;
	while(getline(fmin,my)){
		stringstream ss;
		ss << my;
		string myPOK;
		while(ss >> myPOK){
			for(i=0;i<493;i++){
				if(myPOK.length() <3){
					int mynum = stoi(myPOK);
					if(mynum == stoi(index[i].num)){
						MY[j].NUM = stoi(index[i].num);
						MY[j].EN = index[i].en;
						j++;
					}
				}
				else if(myPOK == index[i].en || myPOK == index[i].num){
					MY[j].NUM = stoi(index[i].num);
					MY[j].EN = index[i].en;
					j++;
				}
			}
		}
	}
	
	Sort(MY,j);
	for(int k=0;k<j;k++){
		if(repeat(MY,k)==1){
			fmout << MY[k].NUM << " " << MY[k].EN << endl;
		}
	}
	return 0;
}

bool repeat(MYPOK vec[],int z){
	
	bool B=1;

	if(z==0){
		B=1;;
	}
	else{
		for(int a=z-1;a>=0;a--){
			if(vec[a].NUM == vec[z].NUM){
				B=0;
				break;
			}
		}
	}
	return B;	
}

void Sort(MYPOK vec[], int len){
	for(int z=1;z<len;z++){                                 // compare from second card to the last one
		MYPOK key=vec[z];                               // set the 'current' card as key
		int a = z-1;                                    // compare the card before the 'current' one
		while ((a>=0)&& (vec[a].NUM>key.NUM)){
			vec[a+1] = vec[a];
			a--;
		}
		vec[a+1] = key;
	}
}
