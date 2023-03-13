#include<bits/stdc++.h>
using namespace std;

ofstream fout;
ifstream fin;

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average;
};

int main(int argc, char** argv){
    fin.open(argv[1]);
    student s;
    double *avgsc = new double [100];
    int len = 0;
    while(fin >> s.ID){
        fin >> s.name >> s.num_score;
        s.score = new int [s.num_score];
        for(int i=0; i<s.num_score; ++i)
            fin >> s.score[i];
        
        cout << s.ID << " " << s.name << " ";
        for(int i=0; i<s.num_score; ++i)
            cout << s.score[i] << " ";

        int sum = 0, flag = 0;
        sort(s.score, s.score+s.num_score);
        for(int i=s.num_score-1; i>=0; --i){
            sum += s.score[i];
            if(s.num_score - i == 10){
                flag = 1;
                break;
            }
        }

        s.average = (flag == 1? sum/10.0: sum / (double)s.num_score);

        cout << s.average << "\n";
        avgsc[len++] = s.average;
    }

    double sum = 0;
    for(int i=0; i<len; ++i){
        //cout << avgsc[i] << " ";
        sum += (double)avgsc[i];
    }

    double miu = sum / len, tmp = 0;
    for(int i=0; i<len; ++i)
        tmp += pow(avgsc[i] - miu, 2);

    cout << sqrt(tmp/len) << "\n";




}

