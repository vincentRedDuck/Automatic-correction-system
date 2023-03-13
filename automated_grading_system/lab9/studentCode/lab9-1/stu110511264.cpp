#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);
    string s,tmp;
    while(1){
        if(fin.eof()){
            break;
        }
        getline(fin,tmp);
        s+=tmp+'\n';
    }
    string num[100];
    int n=-1,count=0;
    double sum=0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            num[n]+=s[i];
        }
        if(s[i]==':'){
            count++;
            n++;
        }
        
    }
    
    for(int i=0;i<99;i++){
        if(num[i]!="\0"){
            sum+=stoi(num[i]);
        }
    
    }
    
    fout<<fixed<<setprecision(4)<<"The average is: "<<sum/count;
    fin.close();
    return 0;
}
