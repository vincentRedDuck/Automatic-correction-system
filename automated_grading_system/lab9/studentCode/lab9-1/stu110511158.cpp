#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile;
    infile.open(argv[1]);
    string line;
    int x;
    int num=0;
    int value =0;
    double avg =0;
    while(getline(infile,line)) {
        if (line.find(":") == line.length()-1)
            x=0;
        else
            x = stoi(line.substr(line.find(":")+1,line.find("\n")-1));
        value += x;
        num++;
    }
    avg = double(value)/num;
    ofstream outfile;
    outfile.open(argv[2]);
    outfile << "The average is: " << fixed << setprecision(4) << avg;
    return 0;
}
