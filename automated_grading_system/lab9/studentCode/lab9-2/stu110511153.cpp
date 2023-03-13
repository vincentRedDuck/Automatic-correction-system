#include <bits/stdc++.h>
using namespace std;
struct student_data {
    string name;
    int  score[3];
    double  average;

} stdArray[100];

int sortArray[100];

int stuNum;

void proc_sortByAverage();
void proc_sortByName();

int main(int agrc, char *argv[]){
    double sum=0;
    double average;
    int i=0;
    int j=0;
    int k;
    int sortType;
    string s0,s1;
    string s2[4];
    string arg=argv[2];
    ofstream fout;
    if(agrc==4)
        fout.open(argv[3]);
    else
        fout.open(arg+".out");
    ifstream fin(argv[2]);
    if(!strcmp(argv[1],"1"))
    {   
        sortType=1;
    } 
    else {
        sortType=2;
    }
    getline(fin,s0);
    stuNum = stoi(s0);
    j=0;
    while(j<stuNum)
    {
        getline(fin,s1);
        stringstream x(s1);
        i=0;
        sum=0;    
        while(getline(x,s1,' '))
        {
            s2[i]=s1; 
            stdArray[j].name = s2[0];
            if(isdigit(s2[i][0])) {
                k=stoi(s2[i]);
                stdArray[j].score[i-1]=k;
                sum+=k;
            }
            i++;

        }
        stdArray[j].average=double(sum/3);
        j++; 
    }


    if (sortType==1) {
       proc_sortByAverage();
    } 
    else {
       proc_sortByName();
    }

    for ( i=0; i< stuNum ; i++ ) {
        fout<< stdArray[sortArray[i]].name << " " <<  stdArray[sortArray[i]].score[0] << " " <<stdArray[sortArray[i]].score[1];
        fout<<" "<<stdArray[sortArray[i]].score[2]<<" "<<fixed<<setprecision(4)<<stdArray[sortArray[i]].average<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
void proc_sortByAverage(){
    int i, j;
    int k;

    for (i=0; i< stuNum; i++) {
        k=0;
        for (j=0; j< stuNum; j++) {
            if (i!=j) {
                if (stdArray[i].average < stdArray[j].average) {
                    k++;
                }
            }
        }
        sortArray[stuNum-1-k]=i;
    }
}

void proc_sortByName(){
    int i, j;
    int k;
    for (i=0; i< stuNum; i++) {
        k=0;
        for (j=0; j< stuNum; j++) {
            if (i!=j) {
                if (strcmp(stdArray[i].name.c_str(), stdArray[j].name.c_str()) < 0) {
                    k++;
                }
            }
        }
        sortArray[stuNum-1-k]=i;
    }
}
