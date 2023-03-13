#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

struct Poke {
    int idx=0;
    string name="";
};

/*void Find (Poke& p,char agrv[]) {
    ifstream dex(agrv);
    while (!dex.eof()) {
        int idx;
        string name,n;
        dex >> idx >> name >> n;
        if (idx == p.idx) {
            p.name = name;
            return;
        }else if (name == p.name) {
            p.idx = idx;
            return;
        }else {
            continue;
        }
    }
    dex.close();
}*/

void fill (Poke p[],char agrv[]) {
    ifstream dex(agrv);
    string n;
    for (int i=0; i<493; i++) {
        dex >> p[i].idx >> p[i].name >> n;
    }
    dex.close();
}

void Sort(Poke p[], int len) { 
    for (int j=1; j<len; j++) {
        Poke key = p[j];
        int i = j-1;
        while (i>=0 && p[i].idx > key.idx) {
            p[i+1] = p[i];
            i--;
        }
        p[i+1] = key;
    }
}

int main(int agrc, char *agrv[]) {
    ifstream dexin(agrv[1]);
    ofstream dexout(agrv[2]);
    stringstream ss;
    string line;
    while (getline(dexin,line)) {
        ss.str(line);
        string idx;
        ss >> idx;
        string Jp,Eng,oT,tT;
        ss >> Jp >> Eng >> oT >> tT;
        dexout << idx << " " << Eng << " " << oT << endl;
        ss << "";
        ss.clear();
    }
    dexin.close();
    dexout.close();

    ifstream fin(agrv[3]);
    ofstream fout(agrv[4]);
    
    Poke p[493];
    fill(p,agrv[2]);
    int ans[493]= {0};
    int count = 0;
    while (fin.peek()==' ') {
        fin.ignore(1,'/');
    }
    while (getline(fin,line)) {
        ss.str(line);
        while (!ss.eof()) {
            //char ch = ss.peek();
            //int i=0;
            string s;
            ss >> s;
            /*if (ch >= '0' && ch <= '9') {
                ss >> i;
                ss.ignore(1,'/');
            }else {
                ss >> s;
                ss.ignore(1,'/');
            }*/
            for (int j=0; j<493; j++) {
                if (p[j].idx == atoi(s.c_str()) || p[j].name == s)
                    ans[j] = 1;
            }
        }
        ss << "";
        ss.clear();
        while (fin.peek()==' ') {
            fin.ignore(1,'/');
        }
    }

    /*for (int i=0; i<count; i++) {
        Find(p[i],agrv[2]);
    }*/

    //Sort(p,count);

    /*for (int i=0; i<count; i++) {
        if (p[i].idx == p[i+1].idx) continue;
        //cout << p[i].idx << " " << p[i].name << endl;
        fout << p[i].idx << " " << p[i].name << endl;
    }*/

    for (int n=0; n<493; n++) {
        if (ans[n] != 0)
            fout << p[n].idx << " " << p[n].name << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
