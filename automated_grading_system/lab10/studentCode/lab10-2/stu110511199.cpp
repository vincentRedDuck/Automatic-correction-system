#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
using namespace std;

struct Poke{
string id;
string en, tn;
};
Poke pdex[500], mypk[500];
int searchPKM(Poke [], int , string ); void insertSort(Poke [], int );

int main (int argc, char **argv) {
    ifstream fin(argv[1]);
    ofstream fot(argv[2]);
    string line, tok;
    int num =0;
    while (getline(fin, line)){
        stringstream ss(line);
        ss >> pdex[num].id >> tok >> pdex[num].en >> pdex[num].tn;
        fot << pdex[num].id << " " << pdex[num].en << " " << pdex[num++].tn << endl;
    }
    fin.close(); fot.close();

    fin.open(argv[3]);
    fot.open(argv[4]);
    int tnt = 0;
    while (fin >> tok) {
        int id = (isdigit(tok[0])? (atoi(tok.c_str())-1):searchPKM(pdex, num, tok));
        if (searchPKM(mypk, tnt, pdex[id].en)==-1){ 
            mypk[tnt].id = pdex[id].id; mypk[tnt++].en = pdex[id].en;
        }
    }
    insertSort (mypk, tnt);
    for (int i=0; i<tnt; i++) 
        fot << atoi((mypk[i].id).c_str()) << " " << mypk[i].en << endl;
    fin.close(); fot.close();

    return 0;
}

int searchPKM(Poke vec[], int num, string en) {
    for (int i=0; i<num; i++) {
        if(vec[i].en==en)
             return i;
    }
    return -1;
}
void insertSort(Poke vec[], int len) {
    for (int j=1; j<len; j++) {
        Poke key(vec[j]);
        int i =j-1;
        while ((i>=0)&&(vec[i].id>key.id)) {
            vec[i+1] =vec[i];
            i--;
        } 
        vec[i+1] = key;
    }
}
