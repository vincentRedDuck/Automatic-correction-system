#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

struct student {
    string ID;
    string name;
    int *score;
    int num_score = 0;
    double average = 0;
};

void Sort (int *s, int len) {
    for (int j=1; j<len; j++) {
        int key = s[j];
        int i = j-1;
        while (i>=0 && s[i] > key) {
            s[i+1] = s[i];
            i--;
        }
        s[i+1] = key;
    }
}

int main (int argc, char **argv) {
    ifstream fin(argv[1]);
    int num_student=0;
    string tok;
    while (getline(fin,tok)) num_student++;
    fin.close();
    student *s = new student[num_student];
    fin.open(argv[1]);
    int i=0;
    while (fin >> s[i].ID) {
        fin >> s[i].name >> s[i].num_score;
        cout << s[i].ID << " " << s[i].name << " ";
        s[i].score = new int [s[i].num_score];
        for (int j=0; j < s[i].num_score; j++) {
            fin >> s[i].score[j];
            cout << s[i].score[j] << " ";
        }
        int *sorted = new int[s[i].num_score];
        for (int n=0; n<s[i].num_score; n++) {
            sorted[n] = s[i].score[n];
        }
        Sort(sorted,s[i].num_score);

        /*
        cout << endl;
        for (int n=0; n<s[i].num_score; n++)
            cout << sorted[n] << " ";
        */

        for (int n=((s[i].num_score > 10)? s[i].num_score-10:0); n < s[i].num_score; n++) {
            s[i].average += sorted[n];
        }
        //cout << s[i].average << endl;
        s[i].average /= ((s[i].num_score >= 10)? 10:s[i].num_score);
        cout << s[i].average << endl;
        i++;
    }
    double S_D = 0;
    double avg = 0;
    for (int i=0; i < num_student; i++) {
        avg += s[i].average;
    }
    avg /= num_student;
    for (int i=0; i < num_student; i++) {
        S_D += (s[i].average-avg)*(s[i].average-avg);
    }
    S_D = sqrt(S_D/num_student);
    cout << S_D << endl;
    fin.close();
    return 0;
}
