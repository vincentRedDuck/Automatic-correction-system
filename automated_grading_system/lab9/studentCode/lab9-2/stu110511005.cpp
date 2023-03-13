#include<iostream>
using namespace std;
#include<fstream>    
#include<iomanip>
#include<cstring>

const int MAX = 100;
struct per {
    string name;
    int g1;
    int g2;
    int g3;
    double avg;
};
    
int main(int argc , char* argv[]) {
    ifstream inFile;
    ofstream outFile;
    /*if (argc == 3) {    
        outFile.open(strcat(argv[2] , ".out"));  
    */
    //can't be written here cuz the name of the file will be changed,so it can't be open later
    inFile.open(argv[2]);
    struct per stu[MAX];
    string line;
    int i;
    inFile >> i;

    for (int k=0 ; k<i ; k++) {
        inFile >> stu[k].name >> stu[k].g1 >> stu[k].g2 >> stu[k].g3;
        stu[k].avg = (stu[k].g1 + stu[k].g2 + stu[k].g3) / 3.0;
    }
    if (atoi(argv[1]) == 2) {
        per key;
        for (int k = 1; k<i; k++) {
            key = stu[k];
            int j = k - 1;
            while ((key.name < stu[j].name) && j >= 0) {
                stu[j+1] = stu[j];
                j--;
            }
            stu[j+1] = key;
        }
    }

    else if (atoi(argv[1]) == 1) {
        per key;
        for (int k = 1; k<i; k++) {
            key = stu[k];
            int j = k - 1;
            while (key.avg < stu[j].avg && j >= 0) {
                stu[j+1] = stu[j];
                j--;
            }
            stu[j+1] = key;
        }
    }
    if (argc==3)
    outFile.open(strcat(argv[2],".out"));
    else 
    outFile.open(argv[3]);
    for (int k=0 ; k<i ; k++) {
        outFile << stu[k].name << " " << stu[k].g1 << " " << stu[k].g2 << " " << stu[k].g3 << " "<< 
                   fixed << setprecision(4) << stu[k].avg << endl;
    }
    return 0;
}
