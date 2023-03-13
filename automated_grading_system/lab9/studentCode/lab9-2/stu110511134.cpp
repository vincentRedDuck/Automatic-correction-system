#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;
const int MAX=100;


struct SCORE{
	string name;
	int subj[3];
	double avg;
};

void insertSort(SCORE [], int, int);

int main (int argc, char **argv){
	SCORE stu[MAX];
	int opt(atoi(argv[1]));
	ifstream fin(argv[2]);
	
	string fName((argc==4)?string(argv[3]):(string(argv[2])+".out"));
	ofstream fout(fName.c_str());
	
	int num; fin >> num;
	for(int i=0;i<num;i++){
		fin >>stu[i].name >>stu[i].subj[0]>>stu[i].subj[1]>>stu[i].subj[2];
		stu[i].avg = (stu[i].subj[0]+stu[i].subj[1]+stu[i].subj[2])/3.0;
	}
	
	insertSort(stu, num, opt);
	
	for(int i=0;i<num;i++){
		fout <<stu[i].name <<" "<<stu[i].subj[0]<<" "<<stu[i].subj[1]<<" "<<
		stu[i].subj[2]<<" "<< fixed << setprecision(4) <<stu[i].avg <<endl;
	}
	fin.close();fout.close();
	return 0;
}
bool bigger(SCORE x,SCORE y,int cmp){
	return((cmp==2)?(x.name>y.name):(x.avg>y.avg));
}

void insertSort(SCORE vec[],int len,int cmp){
	for(int j=1; j<len; j++){
		SCORE key(vec[j]);
		int i=j-1;
		while((i>=0)&&(bigger(vec[i], key,cmp))){
			vec[i+1] = vec[i];
			i--;
		}
		vec[i+1] = key;
	}
}
