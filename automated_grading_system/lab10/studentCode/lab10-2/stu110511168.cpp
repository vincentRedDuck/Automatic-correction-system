#include<bits/stdc++.h>
using namespace std;

ifstream fin;
ofstream fout;
string pok[1100][3];
int num = 0;

int find(string s){
    for(int i=0; i<num; ++i)
        if(s == pok[i][1])
            return i;

    return -1;
}

int main(int argc, char **argv){
    fin.open(argv[1]);
    fout.open(argv[2]);
    for(int i=0; i<1100; ++i){
        fin >> pok[i][0];
        if(fin.eof())
            break;

        ++num;
        string tmp;
        fin >> tmp >> pok[i][1] >> pok[i][2];
        fin.ignore(1024, '\n');
    }
    
    for(int i=0; i<num; ++i)
        for(int j=0; j<3; ++j)
            fout << pok[i][j] << (j==2? "\n": " ");

    fin.close();
    fin.open(argv[3]);
    fout.close();
    fout.open(argv[4]);
    
    vector<int> v;
    string s;
    while(fin >> s){
        if(isdigit(s[0]))
            v.push_back(stoi(s)-1);

        else
            v.push_back(find(s));
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        if(i > 0)
            if(v[i] == v[i-1])
                continue;
        
        fout << v[i] + 1 << " " << pok[v[i]][1] << "\n";
    }

    return 0;
}
