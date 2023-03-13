#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

struct score {
    string name;
    int score_1;
    int score_2;
    int score_3;
    double avg;
};

void func1(score NAME[],int);
void func2(score NAME[],int);

int main (int argc, char *argv[]) {
    ifstream inFile(argv[2]);
    int num;
    inFile >> num;
    score NAME[num];
    for(int i=0;i<num;i++) {
        inFile >> NAME[i].name >> NAME[i].score_1 >> NAME[i].score_2 >> NAME[i].score_3;
        NAME[i].avg=(NAME[i].score_1+NAME[i].score_2+NAME[i].score_3)/3.;
    }
    if(argc==3) {
        if(atoi(argv[1])==1) {
            string aa = string(argv[2])+".out";
            ofstream outFile(aa.c_str());
            func1(NAME,num);
            for(int i=0;i<num;i++) {
                outFile << NAME[i].name << " " << NAME[i].score_1 << " " << NAME[i].score_2 << " " << NAME[i].score_3 << " " << fixed << setprecision(4) << NAME[i].avg << endl;
            }
        }
        else if(atoi(argv[1])==2) {
            string aa = string(argv[2])+".out";
            ofstream outFile(aa.c_str());
            func2(NAME,num);
            for(int i=0;i<num;i++) {
                outFile << NAME[i].name << " " << NAME[i].score_1 << " " << NAME[i].score_2 << " " << NAME[i].score_3 << " " << fixed << setprecision(4) << NAME[i].avg << endl;
            }
        }
    }
    else {
        if(atoi(argv[1])==1) {
            ofstream outFile(argv[3]);
            func1(NAME,num);
            for(int i=0;i<num;i++) {
                outFile << NAME[i].name << " " << NAME[i].score_1 << " " << NAME[i].score_2 << " " << NAME[i].score_3 << " " << fixed << setprecision(4) << NAME[i].avg << endl;
            }
        }
        else if(atoi(argv[1])==2) {
            ofstream outFile(argv[3]);
            func2(NAME,num);
            for(int i=0;i<num;i++) {
                outFile << NAME[i].name << " " << NAME[i].score_1 << " " << NAME[i].score_2 << " " << NAME[i].score_3 << " " << fixed << setprecision(4) << NAME[i].avg << endl;
            }
        }
    }
    
    inFile.close();

    return 0;
}

void func1(score NAME[],int num) {
    for(int i=1;i<num;i++) {
        int j=i-1;
        score key=NAME[i];
        while(j>=0&&NAME[j].avg>key.avg) {
            NAME[j+1]=NAME[j];
            j--;
        }
        NAME[j+1]=key;
    }        
}

void func2(score NAME[],int num) {
    for(int i=1;i<num;i++) {
        int j=i-1;
        score key=NAME[i];
        while(j>=0&&(strcmp(NAME[j].name.c_str(),key.name.c_str())>0)) {
            NAME[j+1]=NAME[j];
            j--;
        }
        NAME[j+1]=key;
    }
}
