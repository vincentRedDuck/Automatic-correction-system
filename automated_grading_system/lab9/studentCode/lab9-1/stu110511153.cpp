#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
    string s;
    char cstr[30];
    double sum=0;
    int counter=0;
    double averge;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    while(getline(fin,s,':'))
    {
        strcpy(cstr,s.c_str());
        if(isdigit(cstr[0]))
            sum += atoi(cstr);
        else
            sum=sum;
        counter++;
        
        cstr[30]={0};
    }
    
    averge=sum/(counter-1);

    fout<<"The average is: "<<fixed<<setprecision(4)<<averge;
    return 0;
}
