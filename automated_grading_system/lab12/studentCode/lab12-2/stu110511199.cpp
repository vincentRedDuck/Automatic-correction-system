#include<iostream>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

struct student {
    string ID;
    string name;
    int *score;
    int num;
    double average ; //top 10 scores average
};
//const int MAX = 10;
int size(ifstream &fi);

int main (int argc, char** argv) {
    ifstream fi(argv[1]);
    int MAX = size(fi);
    student stu[MAX];
    fi.close();
    ifstream fin(argv[1]);
    for (int i=0; i<MAX; i++) {
        stu[i].average = 0.0;
        fin >> stu[i].ID >> stu[i].name >> stu[i].num;
        cout << stu[i].ID << " " << stu[i].name << " " ;
        stu[i].score = new int [stu[i].num];
        for (int j=0; j<stu[i].num; j++) {
            fin >> stu[i].score[j];
            cout << stu[i].score[j] << " ";
        }
        //vector <int> vec (stu[i].score, (stu[i].score+stu[i].num));
        sort (stu[i].score, (stu[i].score+stu[i].num));
        for (int j=1; j<=stu[i].num; j++) {
            stu[i].average += 1.0*stu[i].score[(stu[i].num-j)];
            if (j==10||j==(stu[i].num)) {
                stu[i].average /= j;
                break;
            }
        } cout << stu[i].average << endl;

    }
    double u = 0.0, n=0.0;
    for (int i=0; i<MAX; i++) {
        /*cout << stu[i].ID << " " << stu[i].name << " " ;
        for (int j=0; j<stu[i].num; j++) {
           cout << stu[i].score[j] << " ";
        }
        cout << stu[i].average << endl;*/
        u += stu[i].average;
    }
    u /= (1.0*MAX);
    for (int i=0; i<MAX; i++) {
        n += pow((stu[i].average - u),2);
        delete [] stu[i].score;
    }
    cout << pow(n/(1.0*MAX),0.5) << endl;

    fin.close();
    
    return 0;
}

int size(ifstream &fi){
    string str;
    int n=0;
    while (getline(fi,str))
        n++;
    return n;
}

