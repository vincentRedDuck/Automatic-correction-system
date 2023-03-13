#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;

string str,tok;
int num = 0;
struct dex{
	string id;
	string jp;
	string en;
	string oc;
	string sc;
};

int search(dex[],string,int);

dex pdex[1000];
dex mdex[1000];

int main(int arg,char **argv){
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	while(getline(fin,str)){
		stringstream ss(str);
		ss >> pdex[num].id >> pdex[num].jp >> pdex[num].en >> pdex[num].oc;
		fout << pdex[num].id << " " << pdex[num].en << " " << pdex[num].oc << endl;
		num++;
	}	
	fin.close();
	fout.close();

	fin.open(argv[3]);
	fout.open(argv[4]);
	int con = 0;
	while(fin >> str){
		int id = (isdigit(str[0])? atoi(str.c_str()) : search(pdex,str,num));
		if (search(mdex,pdex[id-1].en,con) == -1){
			mdex[con].id = to_string(id);
			mdex[con].en = pdex[id-1].en;
			con++;
		}
		
	}
	for (int i = 1;i < con;i++){
		dex key = mdex[i];
		int j = i-1;
		while ((j >= 0)&&(atoi(mdex[j].id.c_str()) > atoi(key.id.c_str()))){
			mdex[j+1] = mdex[j];
			j--;
		}
		mdex[j+1] = key;
	}
	for(int i = 0;i < con;i++){
		fout << mdex[i].id << " " << mdex[i].en << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

int search(dex dex[],string str,int n){
	for(int j = 0; j < n;j++){
		if (dex[j].en == str)
			return atoi(dex[j].id.c_str());
	}
	return (-1);
        //else
	//	return search(*pdex,str,num,i+1);
}
