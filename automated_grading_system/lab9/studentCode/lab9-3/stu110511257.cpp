#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
const int SZ = 36;

struct ss {
    char ch;
    string morse;
};

void init(ss [], int);

int main (int argc, char *argv[]) {
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    char *mode = argv[3];
    
    ss arr[SZ];
    init(arr, SZ);    

//    for (int i=0; i<SZ; i++) {
//        cout << arr[i].ch << " " << arr[i].morse << endl;
//    }
    char cc, sp;
    string mm, st;
    int p, l;
    if (!strcmp(mode, "d")) {
        while (getline(fin, mm)) {
            l = mm.length();
            while (l>0) {
                p = mm.find(' ');
                st = mm.substr(0, p);
                for (int i=0; i<SZ; i++) {
                    if (st == arr[i].morse) {
                        fout << arr[i].ch;
                        break;
                    }
                }
                mm = mm.erase(0,p);
                if (mm.substr(0,1)==" ")
                    mm = mm.erase(0,3);
                if (mm.substr(0,1)==" ") {
                    fout << " ";
                    mm = mm.erase(0,4);
                }
                l = mm.length();
            }
            fout << endl;
        }
    }
    else {
        while (fin >> cc) {
            for (int i=0; i<SZ; i++) {
                if (cc == arr[i].ch) {
                    fout << arr[i].morse << "   ";
                    break;
                }
            }
            if (fin.peek() == '\n') {
                fout << endl;
            } else if (fin.peek() == ' ') {
                fout << "    ";
            }
        }
    }


    return 0;
}

void init(ss v[], int n) {
    
    v[0].morse = ".-";
    v[1].morse = "-...";
    v[2].morse = "-.-.";
    v[3].morse = "-..";
    v[4].morse = ".";
    v[5].morse = "..-.";
    v[6].morse = "--.";
    v[7].morse = "....";
    v[8].morse = "..";
    v[9].morse = ".---";
    v[10].morse = "-.-";
    v[11].morse = ".-..";
    v[12].morse = "--";
    v[13].morse = "-.";
    v[14].morse = "---";
    v[15].morse = ".--.";
    v[16].morse = "--.-";
    v[17].morse = ".-.";
    v[18].morse = "...";
    v[19].morse = "-";
    v[20].morse = "..-";
    v[21].morse = "...-";
    v[22].morse = ".--";
    v[23].morse = "-..-";
    v[24].morse = "-.--";
    v[25].morse = "--..";
    v[26].morse = "-----";
    v[27].morse = ".----";
    v[28].morse = "..---";
    v[29].morse = "...--";
    v[30].morse = "....-";
    v[31].morse = ".....";
    v[32].morse = "-....";
    v[33].morse = "--...";
    v[34].morse = "---..";
    v[35].morse = "----.";
    
    for (int i=0; i<26; i++) {
        v[i].ch = char ('A'+i);
    }
    for (int i=26; i<n; i++) {
        v[i].ch = char ('0'+i-26);
    }
}string morse;
