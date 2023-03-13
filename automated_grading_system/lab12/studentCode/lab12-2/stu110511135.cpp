#include<iostream>
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
void sortarray(student*, int);
int main(int argc, char**argv){
    ifstream fin(argv[1]);
    string l;
    string word;
    int stunum=0;
    while(getline(fin,l)){
        stunum++;
    }
    fin.clear();fin.seekg(ios::beg);
    int scorenum;
    double sumavg, avg;
    double *avgarr = new double[stunum];
    int count=0;
    while(getline(fin,l)){
        stringstream ss(l);
        student *stu = new student;
        ss >> word; cout << word << " ";
        ss >> word; cout << word << " ";
        ss >> word; scorenum = atoi(word.c_str());
        stu->score = new int[scorenum];
        for(int j=0; j<scorenum; j++){
            ss >> word;
            stu->score[j] = atoi(word.c_str());
        }
        int min = stu->score[0];
        int a=0;
        for(int j=0; j<scorenum; j++){
           cout << stu->score[j] << " ";
        }
        int s2 = scorenum;
        /*if(scorenum>10){
            for(int j=0; j<scorenum-10; j++){
                for(int k=0; k<scorenum; k++){
                    if(stu->score[k]<min){
                        min = stu->score[k];
                        a = k;          
                    }
                }
                for(int k=0; k<scorenum; k++){
                    if(stu->score[k]!=-1){min = stu->score[k];break;}
                }
                
                stu->score[a]=-1;
            }
            scorenum=10;
        }*/
        sortarray(stu,scorenum);
        s2 = (scorenum>10 ? 10 : scorenum);
        /*for(int j=0; j<s2; j++){
            cout << stu->score[j] << " ";
        } */
        double sum = 0;
        for(int j=0; j<s2; j++){
            //if(stu->score[j]!=-1) 
            sum+=stu->score[j];
        }
        stu->average = sum/s2;
        cout << stu->average;
        avgarr[count] = stu->average;        
        cout << endl;
        sum=0;count++;
    }
    double avgsum=0, avgavg;
    for(int i=0; i<stunum; i++){
        avgsum += avgarr[i];
        //cout << avgarr[i] << " ";
    }
    avgavg = avgsum/stunum;
//    cout << stunum << endl;
    double sdsum =0; 
    for(int i=0; i<stunum; i++){
        sdsum+=pow(avgarr[i]-avgavg,2);
    }
    cout << sqrt(sdsum/stunum) << endl;
return 0;
}

void sortarray(student *stu, int len) {
  for (int j=1; j<len; j++) {
    int key = stu->score[j];
    int i = j-1;
    while (i>=0 && stu->score[i]<key) {
      stu->score[i+1] = stu->score[i];
      i--; 
    }
    stu->score[i+1] = key;
  }
}

