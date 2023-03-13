#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>
using namespace std;

struct student{
	string ID;
	string name;
	int *score;
       	int num_score;	
	double average;
};
student sort(string);
double RE1(int [],int);
bool Big(int,int);

int main(int argc,char **argv){
	int MAX = 10;
	ifstream fin(argv[1]);	
	string save;
	int n = 0;
	student *list = new student[MAX];

	while(getline(fin,save)){
	 	list[n] = sort(save);
		n++;

	if(n>=MAX){
		MAX*=2;
		student *tmp =new student[MAX];
		for(int i=0;i<n;i++){
			tmp[i] = list[i];
		}
		delete [] list;
		list = tmp;
	}
	
	}
       for(int i= 0;i<n;i++){
       cout << list[i].ID <<" "<< list[i].name<<" ";
       	for(int j=0;j<list[i].num_score;j++) {cout << list[i].score[j]<<" "; }
	cout << list[i].average << endl;
       }
       double sum =0.0;
	for(int i=0;i<n;i++){
		sum += list[i].average;
	}
	sum = sum/n;
	double fina=0.0;
	for(int i=0;i<n;i++){
		fina += (list[i].average- sum)*(list[i].average - sum);
	}
	fina = sqrt(fina/n);
	cout << fina << endl;

}

student sort(string save){

	stringstream pipe(save);
	student nowl;

	pipe >> nowl.ID ;
	pipe >> nowl.name;
	pipe >> nowl.num_score;
	nowl.score = new int[nowl.num_score];
	for(int j=0;j<nowl.num_score;j++){
		pipe >> nowl.score[j] ;
	}
	pipe.clear();

	int *ss = new int[nowl.num_score];
	for(int i=0;i<nowl.num_score;i++){
	ss[i] = nowl.score[i];
	}

	nowl.average = RE1(ss, nowl.num_score);	
	
	return nowl;
}


double RE1(int whole[],int count){
	int Key = 0;
	double ave;

	for(int i=1;i<count;i++){
		Key = whole[i];
		int j =i-1;
		while(j>=0 && Big(whole[j],Key)){
		whole[j+1] = whole[j]; 
		j--;
		}
		whole[j+1] = Key; 	
	}

	double tot = 0;
	if(count>=10){
		for(int i=0;i<10;i++){
			tot += whole[i];
		}
		ave = tot/10;
	}else{
		for(int i=0;i<count;i++){
			tot += whole[i];
		}
		ave = tot/count;
	}
	return ave;
}

bool Big(int x, int y){

	return x<y;
}


