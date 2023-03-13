#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <algorithm>
using namespace std;
struct Ve{
    string name;
    int g1;
    int g2;
    int g3;
    double avg;
};

bool compare1(Ve i1, Ve i2)
{
    return (i1.avg < i2.avg);
}
bool compare2(Ve i1, Ve i2)
{
    return (i1.name < i2.name);
}
int main(int argc,char * argv[]){
    string outname;
   
    if (argc ==3){
        outname = argv[2];
        outname += ".out";
    }
    if (argc ==4){
        outname = argv[3];
    }
    
    ifstream fin;
    fin.open(argv[2]);
    int n ;
    fin >> n;
    Ve table[n];
    string s;
    int g1,g2,g3;
    double avg;
    for(int i =0 ;i<n;i++){
        fin >> s>>g1>>g2>>g3;
        avg = (g1+g2+g3+0.0)/3.0;
        table[i].name = s;
        table[i].g1 = g1;
        table[i].g2 = g2;
        table[i].g3 = g3;
        table[i].avg = avg;
    }
    if(strcmp(argv[1],"1")==0){
        std::sort(table,table+n,compare1);
    }
    else{
        std::sort(table,table+n,compare2);
    }
    ofstream fout;
    fout.open(outname);
    int max =n;
    for(int j=0;j<max;j++){

        fout<<table[j].name<<" "<<table[j].g1<<" "<<table[j].g2<<" "<<table[j].g3<<" "<<fixed<<setprecision(4)<<table[j].avg<<endl;
    }
    fout.close();
    return 0;
}
