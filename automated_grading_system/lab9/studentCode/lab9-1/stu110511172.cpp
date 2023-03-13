#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int main(int argc, char *argv[]){
    char *instr = argv[1];
    char *outstr = argv[2];
    
    string line;
    ifstream fin;
    ofstream fout;
    fin.open(instr);
    fout.open(outstr);
    double t=0.0;
    double sum=0.0;
    while(getline(fin,line)){
        int a;
        a=line.find(":");
        line.erase(0,a+1);
        if(!(line == "")){
        sum += stoi(line);}
        t++;
}
    fout <<fixed << setprecision(4) << "The average is: "<< sum/t;
    fin.close();
    fout.close();

return 0;
}
