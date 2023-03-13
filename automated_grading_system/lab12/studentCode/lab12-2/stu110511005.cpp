#include<iostream>
using namespace std;
#include<string>
#include<cmath>
#include<fstream>

struct student {
    string ID;
    string name;
    int *score;
    int num_score;
    double average;
};

int main(int argc , char* argv[]) {
    int num_stu=0;
    int score[100];
    ifstream inFile;
    inFile.open(argv[1]);
    string line;
    while (getline(inFile,line)) {
        num_stu++;
    }
    inFile.close();
    inFile.open(argv[1]);

    student *x;
    x = new student [num_stu];
    for (int k=0 ; k<num_stu ; k++) {
        inFile >> x[k].ID >> x[k].name >> x[k].num_score ;
        x[k].score = new int [x[k].num_score];
        for (int i=0 ; i<x[k].num_score ; i++) {
            inFile >> x[k].score[i];
        }
        cout << x[k].ID << " " << x[k].name << " ";
        for (int j=0 ; j<x[k].num_score ; j++) {
            cout << x[k].score[j] << " " ;
        }

        if (x[k].num_score>10) {
            for( int i=0 ; i<x[k].num_score ; i++ ) {
                for( int j=i+1 ; j<x[k].num_score ; j++ ) {
                    if( x[k].score[i] < x[k].score[j] ) {
                        int tmp;
                        tmp = x[k].score[i];
                        x[k].score[i] = x[k].score[j];
                        x[k].score[j] = tmp;
                    }
                }
            }    
            double sum=0.0;      
            for (int i=0 ; i<10 ; i++) {
                sum+=x[k].score[i];
            }
            x[k].average = sum/10.0;
        }

        else {
            double sum=0.0;
            for (int i=0 ; i<x[k].num_score ; i++) {
                sum+=x[k].score[i];
            }
            x[k].average = sum/x[k].num_score;
        }/*
    double SD;
    double ss=0;
    for (int i=0 ; i<num_stu ; i++) {
        ss+=x[i].average;
    }
    double aa = ss/num_stu;
    double sss;
    for (int i=0 ; i<num_stu ; i++) {
        sss+=(x[i].average-aa)*(x[i].average-aa);
    }
    SD = sqrt(sss/num_stu);
    cout << "ppp\n";*/
        cout << x[k].average << " ";
        cout << endl;
    }
    double SD;
    double ss=0;
    for (int i=0 ; i<num_stu ; i++) {
        ss+=x[i].average;
    }
    double aa = ss/num_stu;
    double sss;
    for (int i=0 ; i<num_stu ; i++) {
        sss+=(x[i].average-aa)*(x[i].average-aa);
    }
    SD = sqrt(sss/num_stu);

    cout << SD << endl;
    return 0;
}
