#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
using namespace std;

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average;//top 10 scores average
};

void Insertion_Sort(int vec[],int size){
    for (int jdx = 1; jdx < size; jdx++) {
        int key = vec[jdx];
        int idx = jdx - 1;
        while ( idx >= 0 && vec[idx] < key) {
            vec[idx+1] = vec[idx];
            --idx;
        }
        vec[idx+1] = key;
    }  
}

int main(int argc,char *argv[]){
    ifstream inf;
    inf.open(argv[1]);
    student *list;
    list = new student[100];
    istringstream iss;
    int n=0;
    double sum;
    int scores[100];
    string line;
    while(getline(inf,line)){//將每個仁資料岔入list
        sum = 0;
        iss.str(line);
        iss>>list[n].ID>>list[n].name>>list[n].num_score;
        list[n].score = new int [list[n].num_score];
        for(int i=0;i<list[n].num_score;i++){
            iss >> list[n].score[i];
        }
        for(int i=0;i<list[n].num_score;i++){
            scores[i]=list[n].score[i];
        }
        Insertion_Sort(scores,list[n].num_score);
        for(int i=0;i<((list[n].num_score>10)?10:list[n].num_score);i++){
            sum+=scores[i];
        }
        list[n].average = sum/((list[n].num_score>10)?10:list[n].num_score);
        iss.clear();
        n++;
    } 
  
    double total=0;
    double allavg;
    for(int i=0;i<n;i++){
        total+=list[i].average;
    }
    allavg = total/n;//全部人平均
    
    double totalOFSD;
    for(int i=0;i<n;i++){
        totalOFSD += pow((list[i].average-allavg),2);
    }

    for(int i=0;i<n;i++){
        cout<<list[i].ID<<" "<<list[i].name<<" ";
        for(int j=0;j<list[i].num_score;j++){
            cout<<list[i].score[j]<<" ";
        }
        cout<<list[i].average<<endl;
    }
    cout<<pow((totalOFSD/n),0.5)<<endl;
    inf.close();
    return 0;
}
