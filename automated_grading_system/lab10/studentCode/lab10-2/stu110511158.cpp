#include<iostream>
#include<fstream>
#include<sstream>
#include<cctype>
using namespace std;

struct POKEMON {
    int id;
    string en,tn; //English name & Chinese name
};

POKEMON pdex[500], mypk[500];
int searchPKM(POKEMON[], int, string);
void insertSort(POKEMON[], int);

int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    ofstream fot(argv[2]);

    string line, tok;
    int num = 0;
    while (getline(fin,line)) {
        stringstream ss(line);
        ss >> pdex[num].id >> tok >> pdex[num].en >> pdex[num].tn;
        if (pdex[num].id >=1 && pdex[num].id <=9) {
        fot << "00" << pdex[num].id << " " << pdex[num].en << " " << pdex[num++].tn << endl;
        }
        else if (pdex[num].id >=10 && pdex[num].id <=99) {
        fot << "0" << pdex[num].id << " " << pdex[num].en << " " << pdex[num++].tn << endl;
        }
        else {
        fot << pdex[num].id << " " << pdex[num].en << " " << pdex[num++].tn << endl;
        }
    }
    fin.close();
    fot.close();

    fin.open(argv[3]);
    fot.open(argv[4]);
    int cnt = 0;
    while (fin >> tok) {
        int id = (isdigit(tok[0])? atoi(tok.c_str()): searchPKM(pdex,num,tok));
        if (searchPKM(mypk,cnt,pdex[id-1].en) == -1) {
            mypk[cnt].id = id;
            mypk[cnt].en = pdex[id-1].en;
            cout<<mypk[cnt].id<<" "<<mypk[cnt].en<<endl;
            cnt++;
        }
    }
    insertSort(mypk,cnt);
    for (int i = 0; i<cnt; i++) 
        fot << mypk[i].id << " " << mypk[i].en << endl;
    fin.close();
    fot.close();

    return 0;
}

int searchPKM(POKEMON vec[], int num, string en) {
    for (int i = 0;i < num;i++) {
        if (vec[i].en == en)
            return vec[i].id;
    }
    return -1;
}

void insertSort(POKEMON vec[], int len) {
    for (int j=1;j<len;j++) {
            POKEMON key(vec[j]); //CARD key = vec[j];
            int i = j-1;
            while ((i>=0) && (vec[i].id>key.id)) {
                vec[i+1] = vec[i];
                i--;
            }
            vec[i+1] = key;
    }
}


