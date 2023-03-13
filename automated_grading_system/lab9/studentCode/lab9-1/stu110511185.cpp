//File: lab9-2-1.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
int main(int argc, char *argv[])
{
    string infn = argv[1];//input file name 
    string outfn = argv[2];//output file name 
    
    ifstream in_file;
    ofstream out_file;

    int nSb = 0;//number of subjects, which equals to number of lines
    string line;//get line
    
    double sum = 0;//summeration of score
    in_file.open(infn.c_str());
    while(getline(in_file,line)){
        int sc;
        string scs;
        scs = line.substr(line.find(":")+1);
        if(!(scs[0] >= '0' && scs[0] <= '9')){
            sc =0;
        }
        else{
        sc = stoi(scs);
        //cout << "scs" << scs << endl;
        }
        //cout << sc << endl;
        sum += sc;
        nSb++;
    }
    
    double avg = sum/nSb;
    
    in_file.close();

    out_file.open(outfn,ios::out);
    out_file <<  "The average is: " << fixed <<  setprecision(4) << avg;
    out_file.close();
    return 0;
}
