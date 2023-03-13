/*#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>

struct POKEMON {
    string id;
    string jn ,en ,tcn ,scn ; //
}
int main (int argc , char* argv[]) {
    POKEMON P[500];
    ifstream inFile;
    ofstream outFile;
    inFile.open(argv[1]);
    for (int i=0 ; i<493 ; i++) {
        inFile >> P[i].id >> P[i].jn >> P[i].en >> P[i].tcn >> P[i].scn;
    }
    inFile.close();
    outFile.open(argv[2]);
    for (int i=0 ; i<493 ; i++) {
        outFile << P[i].id << " " << P[i].en << " " << P[i].tcn << endl;
    }
    inFile.open(argv[3]);
    
    return 0;
}*/
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

struct POKEMON
{
    string id;
    string jn, en, tcn, scn; //
};

int main(int argc, char *argv[])
{
    POKEMON P[500];
    ifstream inFile;
    ofstream outFile;
    inFile.open(argv[1]);
    string str;
    int i=0;
    string line;
    while (getline(inFile,line)) {
        stringstream ss(line);
        ss >> P[i].id >> P[i].jn >> P[i].en >> P[i].tcn;
        i++;
    }
    inFile.close();
    outFile.open(argv[2]);
    for (int i = 0; i < 493; i++)
    {
        outFile << P[i].id << " " << P[i].en << " " << P[i].tcn << endl;
    }
    outFile.close();

    inFile.open(argv[3]);
    int own[500] = {0};
    string tofind;
    while(!inFile.eof()){ //到eof停下來
        inFile >> tofind;
        if(tofind.size() < 3 && isdigit(tofind[0])){
            reverse(tofind.begin(), tofind.end());
            while(tofind.size() < 3)tofind.push_back('0');
            reverse(tofind.begin(), tofind.end());
        }
        
        for(int i = 0; i < 500; i++){
            if(P[i].id == tofind || P[i].en == tofind){
                own[i] = 1;
                break;
            }
        }
        
    }

    outFile.open(argv[4]);

    for(int i = 0; i < 500; i++){
        if(own[i] != 0){
            outFile << stoi(P[i].id) << " " << P[i].en << " " /*<< P[i].tcn*/ << endl;
        }
    }
    outFile.close();
    return 0;
}

