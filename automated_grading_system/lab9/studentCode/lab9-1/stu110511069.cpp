#include<string>
#include<fstream>
#include<string>
#include<iostream>
#include <sstream>
#include<iomanip>
using namespace std;
int main(int argc, char *argv[]){
    ifstream fin;
    fin.open(argv[1]);
    string s;
    stringstream ss;
    char ch;
    int sum =0,count = 0,in = 0;

    while(getline(fin,s)){
           ss.clear();
        ss<<s;
        while(ss.peek()!=':'){
            
            ss>>ch;
               }
        ss>>ch;
        bool b = !(ss>>in);
        if(b) in = 0;
        sum += in;
        count ++;
    
    }
    fin.close();
    ofstream fout;
    fout.open(argv[2]);
    fout<<"The average is: "<<fixed<<setprecision(4)<<(sum+0.0)/count;

}
