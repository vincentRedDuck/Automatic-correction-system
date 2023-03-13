#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct student {
    string ID;
    string name;
    int* score;
    int num_score;
    double average; 
};

double aver1(int*a,int size){
    int nu = ( (size<10 ) ? size : 10 );
    int *v = new int[size];
    for(int i=0;i<size;i++){
        v[i] = a[i];
    }
    double sum = 0;
    for(int i=1;i<size;i++){
            int key = v[i];
            int j= i-1;
            while(j>=0 && v[j]<key){
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = key;
        }
        for(int i=0;i<nu;i++){
            sum += v[i];
        }
    return sum / nu;
}
int main(int argc, char** argv) {
    ifstream infile(argv[1]);
    int n1=0 , Max=1;
    student* stu = new student[Max];
    string str;
    int n = 0;  double sum =0;
    while (getline(infile, str)) {
        n1++;
        if (n1 >= Max) {
                Max++;
                student* tmp = new student[Max];
                for (int i = 0; i < n1; i++) {
                    tmp[i] = stu[i];
                }
                delete [] stu;  stu = tmp;
        }
        stringstream ss(str);
        int size;
        ss >> stu[n].ID >> stu[n].name>>size;
        stu[n].score = new int[size];
        stu[n].average = 0;
        for(int i=0;i<size;i++){
            ss>>stu[n].score[i];
        }
        stu[n].num_score = size ;
        stu[n].average = aver1( stu[n].score,size ); 
        sum+=stu[n].average;
        n++;
    }
    double z=0;
    for (int i = 0; i < n1; i++) {
        cout << stu[i].ID << " " << stu[i].name << " ";
        for (int j = 0; j < stu[i].num_score; j++) {
            cout << stu[i].score[j] << " ";
        }
        cout << stu[i].average << endl; z += pow( (stu[i].average-sum/n1) ,2);
    }
    cout<< sqrt(z/n1)<<endl;;
}


