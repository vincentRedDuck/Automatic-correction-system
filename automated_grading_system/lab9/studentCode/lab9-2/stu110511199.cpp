#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

const int MAX = 100;
struct score {
string name;
int sub[3];
double avg;
};
bool bigger(score , score , int );
void insertSort(score[], int , int );

int main(int argc, char **argv) {
    score stu[MAX];
    int opt(atoi(argv[1]));
    ifstream fin(argv[2]);
    string file((argc==4)?string(argv[3]):(string(argv[2])+".out"));
    ofstream fout (file.c_str());
    
    int num; fin >> num;
    for (int i=0; i<num; i++) {
        fin >> stu[i].name >> stu[i].sub[0] >> stu[i].sub[1] >> stu[i].sub[2];
        stu[i].avg = (stu[i].sub[0]+stu[i].sub[1]+stu[i].sub[2])/3.0;
    }
    int cmp((opt==2)?1:2);
    insertSort(stu, num, cmp);
    for (int i=0; i<num; i++) {
        fout << stu[i].name << " " << stu[i].sub[0] << " " << stu[i].sub[1] << " " << stu[i].sub[2] << " " << setprecision(4) << fixed << stu[i].avg << endl;
    }       
    fin.close();
    fout.close();
    return 0;
}

bool bigger(score x, score y, int cmp){
    return ((cmp==1)?(x.name>y.name):(x.avg>y.avg));
}
void insertSort(score vec[], int len, int cmp){
    for (int j=1; j<len; j++) {
        score key(vec[j]);
        int i =j-1;
        while ((i>=0)&&(bigger(vec[i], key, cmp))) {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    }
}
