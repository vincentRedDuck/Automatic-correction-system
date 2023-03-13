#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int see1(string str) {
    int len = str.length(), nu = 0;
    int lim = str.find('?');
    for (int i = 0; i < len; i++) {
        i = str.find('/', i);
        if (i == -1)
            return nu;
        nu = i;
    }
    return -1;
}
int see3(string a){
    int nu=0;
    for(int i=0;;i++){
        nu++;
        i=a.find('/',i);
        if(nu==3)
            return i;
    }
    return -1;
}
int see4(string a){
    int nu=0;
    for(int i=0;;i++){
        nu++;
        i=a.find('/',i);
        if(nu==2)
            return i;
    }
    return -1;
}
int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    string str1;
    while (getline(infile, str1)) {
        int ini = see1 (str1);
        int nuf = str1.find('?');
        int nu1[100] = { nuf }, count = 1;
        for (;; count++) {
            nu1[count] = str1.find('&', nu1[count-1] + 1);
            if (nu1[count] == -1)
                break;
        }
        outfile << "=====" << endl
            <<"Domain name: "<<str1.substr(see4(str1)+1,see3(str1)-see4(str1)-1 )<<endl
            << "Method: " << str1.substr(ini+1, nuf -ini-1) << endl;
        for (int i = 0; i < count; i++) {
            string a = str1.substr(nu1[i] + 1, nu1[i + 1] - nu1[i] - 1);
            int se = a.find('=');
            if (a.substr(se + 1, nu1[i+1] - se) == "")
                continue;
            outfile << a.substr(0, se) << ": " << a.substr(se + 1, a.length() - se) << endl;
        }
    }
    outfile << "=====" << endl;
}


