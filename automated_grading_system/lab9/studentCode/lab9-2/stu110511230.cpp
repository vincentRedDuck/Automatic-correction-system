#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;

struct da{
	string name;
	int g1;
	int g2;
	int g3;
	double avg;
};

da data[101];

int main(int argc, char *arg[]){
	ifstream fin;
	ofstream fout;
	fin.open(arg[2]);
	int peo;
	fin >> peo;
	for (int i = 0;i<peo;i++){
		fin >> data[i].name >>  data[i].g1 >> data[i].g2 >> data[i].g3;
		data[i].avg = (data[i].g1+data[i].g2+data[i].g3)/3.0;
	}
	int sw = atoi(arg[1]);
	switch(sw){
		case 1:
			for (int k = 0; k < peo;k++){
				double key = data[k].avg;
				int j = k-1;
				while (key < data[j].avg && j >= 0){
					data[101] = data[j+1];
					data[j+1] = data[j];
					data[j] = data [101];
					j--;
				}
				data[j+1].avg = key;
			}
			break;
		case 2:
			for (int k = 0; k < peo;k++){
                                string key = data[k].name;
                                int j = k-1;
                                while ((strcmp(key.c_str(),data[j].name.c_str())>0) && j >= 0){
					data[101] = data[j+1];
                                        data[j+1] = data[j];
					data[j] = data[101];
                                        j--;
                                }
                                data[j+1].name = key;
                        }
                        break;
	}
	
	fout.open((argc == 3)?strcat(arg[2],".out"):arg[3]);
	for (int i = 0;i < peo;i++){
		fout << fixed << setprecision(4) << data[i].name << " " << data[i].g1 << " " << data[i].g2 << " " << data[i].g3 << " " << data[i].avg << endl;
	}
	return 0;


}
