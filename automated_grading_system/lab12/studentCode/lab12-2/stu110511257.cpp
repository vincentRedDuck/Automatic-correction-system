#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct student{
    string ID;
    string name;
    int num_score;
    int *score;
    double average;
};

void sort(int *score, int size);

double avg(int *score, int size);

int main (int argc, char **argv) {

    ifstream fin(argv[1]);

    int num_stu(0), jj(0);
    double mu(0);
    string line;
    while (getline(fin, line)) num_stu++;

    fin.clear();
    fin.seekg(ios::beg);
    
    double *avg_of_a_stu = new double [num_stu];
    while (getline(fin, line)) {
        //num_stu++;
        student *a_stu = new student;
        stringstream ss(line);
        ss >> a_stu->ID >> a_stu->name >> a_stu->num_score;
        int n = a_stu->num_score;
        a_stu->score = new int [n];
        for (int i=0; i<n; i++) 
            ss >> a_stu->score[i];
        ss.clear();
        ss.str("");
        
        int *cp = new int [n];
        for (int i=0; i<n; i++) {
            cp[i] = a_stu->score[i];
        }

        sort(cp, n);

        a_stu->average = avg(cp, n);

        mu += a_stu->average;
        
        avg_of_a_stu[jj++] = a_stu->average;

        cout << a_stu->ID << " " << a_stu->name << " ";
        for (int j=0; j<n; j++) {
            cout << a_stu->score[j] << " ";
        }
        cout << a_stu->average;
        cout << endl;

        delete [] cp;
        delete [] a_stu->score;
        delete a_stu;
    }

    mu = mu/num_stu;
    double var(0), sd(0);
    for (int i=0; i<num_stu; i++) 
        var += (avg_of_a_stu[i] - mu) * (avg_of_a_stu[i] - mu);
    sd = pow(var/num_stu, 0.5);
    cout << sd << endl;

    delete [] avg_of_a_stu;
    fin.close();

    return 0;
}

void sort (int *v, int sz) {
    for (int j=1; j<sz; j++) {
        int key = v[j];
        int i = j - 1;
        while (i>=0 && v[i]>key) {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

double avg(int *v, int sz) {
    int sum(0);
    double a(0);
    if (sz<=10) {
        for (int i=0; i<sz; i++) 
            sum += v[i];
        a = 1.0*sum/sz;
    }
    else {
        for (int i=sz-1; i>sz-11; i--)
            sum += v[i];
        a = sum/10.0;
    }
    return a;
}
