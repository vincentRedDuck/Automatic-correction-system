#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

struct student {
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 average
};

//void insertSort(int*, int );
int main(int argc, char **argv) {    
    ifstream infile (argv[1]);
    string line;
    student stu;
    int a = 0;
    double avg[300];
    while (getline(infile,line,'\n')) {
        stringstream ss(line);
        ss >> stu.ID >> stu.name >> stu.num_score;
        cout << stu.ID << " " << stu.name << " ";
        int k = stu.num_score;
        stu.score = new int[k];
        for (int i=0;i<k;i++) {
            ss >> stu.score[i];
            cout << stu.score[i] << " ";
        }
        stu.average = 0;
        if (k <10) {
            for (int i=0;i<k;i++) 
                stu.average += stu.score[i];
            stu.average /= k;
        }
        else if (k >= 10) {
            for (int j=1;j<k;j++) {
                int key=stu.score[j]; //CARD key = vec[j];
                int s = j-1;
                while ((s>=0) && (key > stu.score[s])) {
                    stu.score[s+1] = stu.score[s];
                    s--;
                }   
                stu.score[s+1] = key;
            }
            for (int i=0;i<10;i++) 
                stu.average += stu.score[i];
            stu.average /= 10;
        }
        cout << stu.average << endl;
        avg[a] = stu.average;
        a++;
    }
    double AVG = 0.0;
    double sum = 0.0;
    double sum1 = 0.0;
    for (int i=0;i<a;i++)
        AVG +=avg[i];
    AVG /=a;
    for (int i=0;i<a;i++)
        sum += pow((avg[i] - AVG),2.0);
    sum /=a;
    sum1 = sqrt(sum);
    cout << sum1 << endl;
    delete [] stu.score;
    infile.close();
    return 0;
}

/*void insertSort(int *score, int len) {
    for (int j=1;j<len;j++) {
            student key(vec[j]); //CARD key = vec[j];
            int i = j-1;
            while ((i>=0) && (vec[i].score>key.score)) {
                vec[i+1] = vec[i];
                i--;
            }
            vec[i+1] = key;
    }
}*/
