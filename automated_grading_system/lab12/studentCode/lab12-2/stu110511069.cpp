#include<iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include<cmath>

using namespace std;
struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 scores average
};
bool cmp(int a, int b) {
    return a > b; // 降序排列
}
int main(int argc,char ** argv){
    int cap = 100;
    int n = 0;
    ifstream fin(argv[1]);
    string line;
    student* *arr = new student* [cap];
    while(getline(fin,line)){
        stringstream ss(line);
        if(n>=cap-1){
            cap *=2;
            student* *temp = new student* [cap];
            for(int i =0;i<n;i++){
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
        }
        arr[n] = new student;
        ss>>arr[n]->ID>>arr[n]->name;
        int scn;
        
        ss>> scn;
        arr[n]->num_score = scn;

        int *scores = new int[scn];
        int *stscore = new int[scn];
        for(int i =0;i<scn;i++){
            ss>>scores[i];
            stscore[i] = scores[i];
        }
        sort(stscore,stscore+scn,cmp);
        double avg = 0;
        if(scn<=10){
            for(int i =0;i<scn;i++){
                    avg+= stscore[i];
            }
            avg/=scn;
        }
        else{
            for(int i = 0;i<10;i++){
                avg+=stscore[i];
            }
            avg/=10;
        }
        arr[n]->score = scores;
        arr[n]->average = avg;
        n++;
    }
    n-=1;
    double sum =0;
    for(int i =0;i<=n;i++){
        cout<<arr[i]->ID<<" "<<arr[i]->name<<" ";
        for(int j = 0;j<arr[i]->num_score;j++){
            cout<<arr[i]->score[j]<<" ";
        }
        cout<<arr[i]->average<<endl;
        sum+= arr[i]->average;
    }
    double totalavg = sum /= (n+1);
    sum = 0;
    for(int i = 0;i<=n;i++){
        sum += (arr[i]->average-totalavg)*(arr[i]->average-totalavg);
    }
    sum /= (n+1);
    cout<<sqrt(sum)<<endl;

    


    return 0;           
}
