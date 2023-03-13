#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

int main(int argc, char *argv[]){
    string ifile=argv[1],ofile=argv[2];
    
    ifstream in_file;   
    ofstream out_file;
    string st;
    int scr[50];
    for (int i=0;i<=50;i++)
        scr[i]=0;
    
    in_file.open(ifile.c_str());
    int cnt=0;
    while(!in_file.eof()){
        getline(in_file,st,':');
        if(isdigit(in_file.peek()))
        in_file>>scr[cnt];
        cnt++;
    }
    int sum=0;
    for (int i=0;i<cnt-1;i++){
        sum+=scr[i];
/*        cout<<scr[i]<<endl;*/
    }
    float avg=float(sum)/float(cnt-1);
    
    out_file.open(ofile.c_str(),ios::out);
    out_file<<"The average is: "<<fixed<<setprecision(4)<<avg;
    
    in_file.close();
    out_file.close();
    
    return 0;
}
