#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
    ifstream infile(argv[1]);   
    ofstream outfile(argv[2]);
    string a,b;
    int nu=0; double sum=0;
    while( getline(infile,a) ){
        nu++;
        int x=a.find(":") , y = a.length(),score = 0;
        if(a[y-1] == ':')
            a+"0";
        stringstream( a.substr(x+1,y-x-1) ) >>score;
        sum+=score;
    }
    outfile<<"The average is: "<<fixed<<setprecision(4)<<sum/nu;

    
}
