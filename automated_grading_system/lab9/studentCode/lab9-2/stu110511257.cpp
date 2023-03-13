#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
const int MAX = 100;

struct Grade {
    string name;
    int sco1;
    int sco2;
    int sco3;
    double avr;
};

void bigger(Grade v[], int n, int m) {
    if (m==1) {
        for (int i=1; i<n; i++) {
            Grade key = v[i];
            int j = i-1;
            while (v[j].avr > key.avr && j>=0) {
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = key;
        }
    } else if (m==2) {
        for (int i=1; i<n; i++) {
            Grade key = v[i];
            int j = i-1;
            while (v[j].name > key.name && j>=0) {
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = key;
        }
    }
}

int main (int argc, char *argv[]) {

    char *infilename = argv[2];
    ifstream fin(infilename);
    char outfilename[80];
    
    string outfile(infilename);
    string mode(argv[1]);
    if (argc==3) { 
        int p = outfile.find(".");
//        outfile = outfile.substr(0,p);
        outfile += ".out";
        strcpy(outfilename, outfile.c_str());
    } else if (argc==4) {
        strcpy(outfilename, argv[3]);
    }
    ofstream fout(outfilename);
    
    int num;
    fin >> num;
    Grade arr[MAX];
    for (int i=0; i<num; i++) {
        fin >> arr[i].name; 
        fin >> arr[i].sco1;
        fin >> arr[i].sco2;
        fin >> arr[i].sco3;
        int sum=0;
        sum += arr[i].sco1 + arr[i].sco2 + arr[i].sco3;
        arr[i].avr = (sum*1.0)/3;
    }
    
    if (mode == "1") {
        bigger(arr, num, 1);
        for (int i=0; i<num; i++) {
            fout << arr[i].name << " " << arr[i].sco1 << " " << arr[i].sco2<< " " << arr[i].sco3 << " " << fixed << setprecision(4) << arr[i].avr << endl;
        }
    }
     
    else if (mode == "2") {
        bigger(arr, num, 2);
        for (int i=0; i<num; i++) {
            fout << arr[i].name << " " << arr[i].sco1 << " " << arr[i].sco2<< " " << arr[i].sco3 << " " << fixed << setprecision(4) << arr[i].avr << endl;
        }
    }


    return 0;
}
