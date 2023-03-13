#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct grad {
    string name;
    int a;
    int b;
    int c;
    double sum;
};
int main(int argc, char* argv[]) {
    string str1=argv[2]; str1+=".out";
    if(argc == 4) str1 = argv[3];
    ifstream infile(argv[2]); ofstream outfile(str1);
    int nu1;
    string a;
    grad s[100];
    char ch = argv[1][0];
    infile >> nu1;
    for (int i = -1; i < nu1; i++) {
        getline(infile, a);
        if (i == -1)continue;
        stringstream ss1; ss1.str(a);
        ss1 >> s[i].name; ss1 >> s[i].a;
        ss1 >> s[i].b; ss1 >> s[i].c;
        s[i].sum = (s[i].a + s[i].b + s[i].c) / 3.0;
    }
    if (ch == '1')
    {
        for (int i = 1; i < nu1; i++) {
            int j = i - 1;
            grad key = s[i];
            while (j >= 0 && s[j].sum > key.sum) {
                s[j + 1] = s[j];
                --j;
            }
            s[j + 1] = key;
        }
    }
    else {
        for (int i = 1; i < nu1; i++) {
            int j = i - 1;
            grad key = s[i];
            while (j >= 0 && s[j].name > key.name) {
                s[j + 1] = s[j];
                --j;
            }
            s[j + 1] = key;
        }

    }
    for (int i = 0; i < nu1; i++) {
        outfile <<fixed<<setprecision(4)<< s[i].name 
                << " " << s[i].a << " " << s[i].b<<" "
                << s[i].c << " " << s[i].sum;
        outfile << endl;
    }

}


