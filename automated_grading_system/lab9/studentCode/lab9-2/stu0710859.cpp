#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
using namespace std;

struct data{
    string name;
    int score[3];
    float avg;
};

int main(int argc, char *argv[]){
    ifstream file1;
    ofstream file2;
    string open, rfile = argv[2];
    int count = 1, t, i = 0;
    file1.open(rfile);
    file1 >> open;
    t = stoi(open);
    struct data d[t], temp;
    for(i = 0; i< t ; i++){          
        file1 >> d[i].name >> d[i].score[0] >> d[i].score[1]  >> d[i].score[2]; 
        d[i].avg = (d[i].score[0]+d[i].score[1]+d[i].score[2])/3.0;
    }
    if(argv[1][0] == '1'){
        for(i = 0; i < t-1; i++){
            for(int j = i+1; j < t; j++){
                if(d[i].avg > d[j].avg){
                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
                }
            }
        }
    }
    else if(argv[1][0] == '2'){
        for(i = 0; i < t-1; i++){
            for(int j = i+1; j < t; j++){
                if(d[i].name > d[j].name ){
                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
                }
            }
        }
    }
    if(argv[3]){
        string wfile = argv[3];
        file2.open(wfile, ios::out);
    }
    else{
        rfile += ".out";
        file2.open(rfile, ios::out);
    }
    for(i = 0; i < t; i++){
        file2 << d[i].name << " " << d[i].score[0] << " " << d[i].score[1] << " " << d[i].score[2] << " " << fixed << setprecision(4) << d[i].avg << endl;
    }
    return 0;
}
