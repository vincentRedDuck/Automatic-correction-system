#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

struct stu {
    string name;
    int g[3];
    double avg=0;
};

void Sort(stu s[], int,int op);

int main(int argc, char *argv[]) {
    int op = atoi(argv[1]);//1 - avg; 2 - name

    ifstream fin(argv[2]);
    ofstream fout((argc==3)? strcat(argv[2],".out"):argv[3]);
    
    int num;
    stu s[100];
    fin >> num;
    //fin
    for (int i=0; i<num ; i++) {
        fin >> s[i].name;
        for (int j=0; j<3; j++) {
            fin >> s[i].g[j];
            s[i].avg += s[i].g[j];
        }
        s[i].avg /= 3;
    }
    //Sort
    Sort(s,num,op);
    //fout
    for (int i=0; i<num ; i++) {
        fout << s[i].name << " ";
        for (int j=0; j<3; j++) {
            fout << s[i].g[j] << " ";
        }
        fout << fixed << setprecision(4) << s[i].avg << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

void Sort(stu s[], int len, int op) {
    if (op == 1) {
        for (int j=1; j<len; j++) {
            stu key = s[j];
            int i = j-1;
            while (i>=0 && s[i].avg > key.avg) {
                s[i+1] = s[i];
                i--;
            }
            s[i+1] = key;
        }
    }else {
        for (int j=1; j<len; j++) {
            stu key = s[j];
            int i = j-1;
            while (i>=0 && strcmp(s[i].name.c_str(),key.name.c_str()) > 0) {
                s[i+1] = s[i];
                i--;
            }
            s[i+1] = key;
        }
    }
}
