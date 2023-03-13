#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    ifstream fin;
    fin.open(argv[1]);
    string line;
    int n = 0;
    while(getline(fin,line))
        n++;
    fin.close();
    line = "";
    struct student{
        string ID;
        string name;
        int *score;
        int num_score;
        double avg;
    };
    student *load = new student [n];
    fin.open(argv[1]);
    stringstream s1;
    int i = 0;
    while(getline(fin,line)){
        s1 << line;
        s1 >> load[i].ID >> load[i].name >> load[i].num_score;
        int m = load[i].num_score;
        load[i].score = new int [m];
        for(int j = 0; j < m; j++){
            s1 >> load[i].score[j];             
        }
        i++;
        s1.clear();s1.str("");
    }
    for(int i = 0; i < n; i++){
        cout << load[i].ID << " " << load[i].name << " ";
        int m = load[i].num_score;
        for(int j = 0; j < m; j++)
            cout << load[i].score[j] << " ";
    //}
    //for(int i = 0; i < n; i++){
        double total = 0.0;
        //int m = load[i].num_score;
        if(m <= 10){
            for(int j = 0; j < m; j++)
                total += load[i].score[j];
            load[i].avg = total/m;
        }
        else{
            for(int j = 1; j < m; j++){
                int key = load[i].score[j];
                int idx = j-1;
                while(idx >= 0 && key > load[i].score[idx]){
                    load[i].score[idx+1] = load[i].score[idx];
                    idx--;
                }
                load[i].score[idx+1] = key;
            }
            //for(int j = 0; j < 10; j++)
                //cout << load[i].score[j] << "> ";
            //cout << endl;
            for(int j = 0; j < 10; j++)
                total += load[i].score[j];
            load[i].avg = total/10;    
        }
        cout << load[i].avg << endl;
    }
    double sd, avgg;
    double total = 0.0;
    double x = 0.0;
    for(int i = 0; i < n; i++)
        total += load[i].avg;
    avgg = total/n;
    for(int i = 0; i < n; i++)
        x += pow(load[i].avg - avgg,2);
    sd = sqrt(x/n);
    /*for(int i = 0; i < n; i++){
        cout << load[i].ID << " " << load[i].name << " ";
        int m = load[i].num_score;
        for(int j = 0; j < m; j++)
            cout << load[i].score[j] << " ";
        cout << load[i].avg << endl;
    }*/
    cout << sd << endl;
    return 0;
}
