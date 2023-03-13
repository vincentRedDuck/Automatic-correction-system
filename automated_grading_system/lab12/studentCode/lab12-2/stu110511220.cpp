#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;

struct student {
    string ID;
    string name;
    int *score;
    int num_score;
    double average;   //top 10 scores average;
};

void insertionsort(int *score,int);
double AVG(int *score,int);

int main (int argc, char **argv) {
    ifstream fin(argv[1]);
    int size=0;
    string str;
    while(getline(fin,str))
        size++;                            //size=the number of students;
    student stu[size];
    string line,tok;
    int i=0;
    ifstream inFile(argv[1]);
    while(getline(inFile,line)) {
        stringstream ss(line);
        getline(ss,tok,' ');
        stu[i].ID=tok;
        getline(ss,tok,' ');
        stu[i].name=tok;
        getline(ss,tok,' ');
        stu[i].num_score=atoi(tok.c_str());
        stu[i].score = new int [stu[i].num_score];
        double sum=0;
        cout << stu[i].ID << " " << stu[i].name << " ";
        for(int j=0;j<stu[i].num_score;j++) {
            getline(ss,tok,' ');
            stu[i].score[j]=atoi(tok.c_str());
            cout << tok << " ";
        }
        insertionsort(stu[i].score,stu[i].num_score);
        stu[i].average=AVG(stu[i].score,stu[i].num_score);
        cout << stu[i].average << endl;
        i++;
    }
    double SD=0;
    double avg=0;
    for(int i=0;i<size;i++) {
        avg+=stu[i].average;
    }
    avg/=size;
    for(int i=0;i<size;i++) {
        SD+=pow((stu[i].average-avg),2);
    }
    SD=pow((SD/size),0.5);
    cout << SD << endl;

    return 0;
}

void insertionsort(int *score,int num) {
    if(num<10)
        return;
    else {
        for(int j=1;j<num;j++) {
            int key=score[j];
            int i=j-1;
            while(i>=0&&score[i]<key) {
                score[i+1]=score[i];
                i--;
            }
            score[i+1]=key;
        }
    }
}


double AVG (int *score,int num) {
    double sum=0;
    if(num<10) {
        for(int i=0;i<num;i++) {
            sum+=score[i];
        }
    return sum/num;
    }
    else {
        for(int i=0;i<10;i++) {
            sum+=score[i];
        }
    return sum/10.;
    }
}















