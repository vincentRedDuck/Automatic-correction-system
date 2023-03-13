#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Pdex {
    int id;
    string en, tn;
};

void insertionSort(Pdex v[], int sz) {
    for (int j=1; j<sz; j++) {
        Pdex key = v[j];
        int i = j - 1;
        while (i>=0 && v[i].id>key.id) {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

int main (int argc, char **argv) {
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    stringstream ss;

    string s1;
    string num;
    string jap;
    string eng;
    string newt;
    string oldt;
    string test;
    Pdex arr[493];
    int i = 0;

    while (getline(fin, s1)) {
        ss << s1;
        ss >> num >> jap >> eng >> newt >> oldt >> oldt;
        //if (isalpha(newt[0])) {
        //    eng += " " + newt;
        //    newt = oldt;
        //}
        arr[i].id = stoi(num); arr[i].en = eng; arr[i++].tn = newt;
        fout << num << " " << eng << " " << newt << " " << endl;
        ss << "";
        ss.clear();
    }

    fin.close();
    fout.close();
    
    fin.open(argv[3]);
    fout.open(argv[4]);

    string pet;
    Pdex ii;
    Pdex myP[493];
    int n = 0;
    while (fin>>pet) {
//        cout << pet << endl;
        if (isalpha(pet[0])) {
//            cout << pet << endl;
            for (int j=0; j<493; j++) {
                if (arr[j].en == pet) {
                    myP[n++] = arr[j];
                    arr[j] = {0, "", ""};
                    break;
                }
            }
        } else {
            if (arr[stoi(pet)-1].id != 0) { 
                myP[n++] = arr[stoi(pet)-1];
                arr[stoi(pet)-1] = {0, "", ""};
            }
        }
    }
    
    insertionSort(myP, n);
    for (int j=0; j<n; j++) {
        fout << myP[j].id << " " << myP[j].en << endl;
    }
    
    fin.close();
    fout.close();

    return 0;
}
