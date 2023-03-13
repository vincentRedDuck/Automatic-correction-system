#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);

    double sum = 0;
    int cnt = 0;
    while(1){
        string s;
        fin >> s;
        if(fin.eof())
            break;

        ++cnt;
        int at;
        for(int i=0; i<s.size(); ++i)
            if(s[i] == ':'){
                at = i+1;
                break;
            }
        
        //cout << s.size()-at << "\n";
        if(at != s.size()){
            string t = s.substr(at, s.size()-at);
            sum += stod(t);
        }
    }

    fout << "The average is: ";
    fout << fixed << setprecision(4) << sum/(double)cnt;

    return 0;
}

