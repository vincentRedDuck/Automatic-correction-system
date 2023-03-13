#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int search_for_Pokemon(string);

map<int, string> Pokemon;

int main(int argc, char* argv[]){
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    string run;
    while(getline(fin, run)){
        // cout << run << endl;
        stringstream ss;
        string s1, s2;
        ss << run;
        ss >> s1; fout << s1 << " ";
        ss >> s2;
        ss >> s2; fout << s2 << " ";
        Pokemon.insert(pair<int, string>(stoi(s1), s2));
        ss >> s2; fout << s2 << endl;
    }
    fin.close();
    fout.close();
    // for(map<int, string>::iterator it = Pokemon.begin() ; it != Pokemon.end() ; it++)
    //     cout << it->first << " " << it->second << endl;

    fin.open(argv[3]);
    fout.open(argv[4]);

    map<int, string> my_Pokemon;
    while(getline(fin, run)){
        stringstream ss;
        string s;
        int idx;
        ss << run;
        while(ss >> s){
            idx = search_for_Pokemon(s);
            my_Pokemon.insert(pair<int, string>(idx, Pokemon[idx]));
        } 
    }
    for(map<int, string>::iterator it = my_Pokemon.begin() ; it != my_Pokemon.end() ; it++)
        fout << it->first << " " << it->second << endl;
    fin.close();
    fout.close();

    return 0;
}

int search_for_Pokemon(string in){
    int rtn = -1;
    if(isalpha(in[0])){
        for(map<int, string>::iterator it = Pokemon.begin() ; it != Pokemon.end() ; it++)
            if(it -> second == in)
                rtn = it -> first;
    }
    else
        rtn = stoi(in);
    return rtn;
}