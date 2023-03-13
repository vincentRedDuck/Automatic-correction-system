#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>
using namespace std;

struct student{
	string ID;
	string name;
	int *score;
	int num_score;
	double average;
};
double SortAvg(int[],int);
int main(int argc, char **argv){

	ifstream fin(argv[1]);
	string str;
	int n=0, MAX=10;
	double Avg;
	student *std = new student [MAX];
	while(getline(fin,str)){
		if(n>=MAX){
			MAX *= 2;
			student *tmp = new student [MAX];
			for(int i=0;i<n;i++){
				tmp[i] = std[i];
			}
			delete [] std;
			std = tmp;
		}

		stringstream ss(str);
		ss >> std[n].ID >> std[n].name >> std[n].num_score;
		std[n].score = new int [std[n].num_score];
		int *stdscore = new int [std[n].num_score];
		int sum=0;
		for(int i=0; i<std[n].num_score; i++){
			ss >> std[n].score[i];
			stdscore[i] = std[n].score[i];
		}
		std[n].average = SortAvg(stdscore,std[n].num_score);
		n++;
	}
	for(int i=0;i<n;i++){
		cout << std[i].ID << " " << std[i].name << " ";
		for(int j=0;j<std[i].num_score;j++){
			cout << std[i].score[j] << " ";
		}
		cout << std[i].average << endl;
	}

	double sum =0.0;
        for(int i=0;i<n;i++){
                sum += std[i].average;
        }
        sum = sum/n;
        double fina=0.0;
        for(int i=0;i<n;i++){
                fina += (std[i].average- sum)*(std[i].average - sum);
        }
        fina = sqrt(fina/n);
        cout << fina << endl;



	//cout << Avg;
	return 0;
}

double SortAvg(int vec[], int len){
	int key;
	for(int j=1;j<len;j++){                                 // compare from second card to the last one
		key=vec[j];                               // set the 'current' card as key
		int i = j-1;                                    // compare the card before the 'current' one
		while ((i>=0)&&(vec[i] < key)){
			vec[i+1] = vec[i];
			i--;
		}
		vec[i+1] = key;
	}
	double sum=0;
	double avg = 0.0;
	if(len>=10){
		for(int i=0;i<10;i++){
			sum = sum + vec[i];
		}
		avg = sum/10;
	}
	else{
		for(int i=0;i<len;i++){
			sum = sum + vec[i];
		}
		avg = sum/len;
	}
	return avg;
}

