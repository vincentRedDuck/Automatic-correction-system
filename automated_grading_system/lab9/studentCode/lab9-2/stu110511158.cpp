#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

struct stu {
    string name;
    int grade[3];
    double avg = 0;
};

void Insertsort(stu s[],int,int op);

int main(int argc, char **argv) {
    int op = atoi(argv[1]); //1-avg;2-name;
    
    ifstream infile(argv[2]);
    ofstream outfile((argc == 3)?strcat(argv[2],".out"):argv[3]);
    int num;
    stu s[100];
    infile >> num;
    for (int i = 0;i<num;i++) {
        infile >> s[i].name;
        for (int j = 0;j<3;j++) {
            infile >> s[i].grade[j];
            s[i].avg += s[i].grade[j];
        }
        s[i].avg /=3;
    }
    Insertsort(s,num,op);
    for (int i = 0;i < num; i++) {
        outfile << s[i].name << " ";
        for (int j = 0;j < 3; j++ ) {
            outfile << s[i].grade[j] << " ";
        }
        outfile << fixed << setprecision(4) << s[i].avg << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}

void Insertsort(stu s[], int len, int op) {
    if (op == 1) {
        for (int j=1;j<len;j++) {
            stu key = s[j];
            int i = j-1;
            while (i>=0 && s[i].avg > key.avg) {
                s[i+1] = s[i];
                i--;
            }
            s[i+1] = key;
        }
    }
    else {
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
