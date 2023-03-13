#include<bits/stdc++.h>
using namespace std;

ofstream fout;

struct group{
    string name;
    double score[3];
    double avg = 0.0;
};

void sort_avg(group g[], int len){
    for(int i=0; i<len-1; ++i)
        for(int j=0; j<len-i-1; ++j)
            if(g[j].avg > g[j+1].avg){
                swap(g[j].avg, g[j+1].avg);
                swap(g[j].name, g[j+1].name);
                for(int k=0; k<3; ++k)
                    swap(g[j].score[k], g[j+1].score[k]);
            }

    for(int i=0; i<len; ++i){
        fout << g[i].name << " ";
        for(int j=0; j<3; ++j)
            fout << g[i].score[j] << " ";

        fout << fixed << setprecision(4) << g[i].avg << "\n";
        fout << defaultfloat;
    }
}

void sort_name(group g[], int len){
    for(int i=0; i<len-1; ++i)
        for(int j=0; j<len-i-1; ++j)
            if(g[j].name[0] > g[j+1].name[0]){
                swap(g[j].avg, g[j+1].avg);
                swap(g[j].name, g[j+1].name);
                for(int k=0; k<3; ++k)
                    swap(g[j].score[k], g[j+1].score[k]);
            }
    
    for(int i=0; i<len; ++i){
        fout << g[i].name << " ";
        for(int j=0; j<3; ++j)
            fout << g[i].score[j] << " ";

        fout << fixed << setprecision(4) << g[i].avg << "\n";
        fout << defaultfloat;
    }
}

int main(int argc, char *argv[]){
    ifstream fin;
    fin.open(argv[2]);
    if (argc == 3){
        string filename(argv[2]);
        filename +=  ".out";
        //cout << filename;
        fout.open(filename.c_str());
    }

    else
        fout.open(argv[3]);
    
    int len;
    fin >> len;
    group g[len];
    for(int i=0; i<len; ++i){
        fin >> g[i].name;
        for(auto &x: g[i].score){
            fin >> x;
            g[i].avg += x;
        }
        
        g[i].avg /= 3.0;
    }

    if(*argv[1] == '1')
        sort_avg(g, len);

    else 
        sort_name(g, len);


    return 0;
}

