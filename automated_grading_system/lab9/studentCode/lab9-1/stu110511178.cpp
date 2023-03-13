#include<bits/stdc++.h>

using namespace std;

int main(int s,char *c[]){

    ifstream f1(c[1]);

    ofstream o1(c[2]);


    string score;
    double sum=0,count=0;
    int a;
    while(!f1.eof()){
    getline(f1,score);
    a=score.find(':');
    count++;
    sum+=atof(score.substr(a+1,(score.length()-a-1)).c_str());
    
    
    }
    o1<<"The average is: "<<fixed<<setprecision(4)<<sum/(count-1);



return 0;
}
