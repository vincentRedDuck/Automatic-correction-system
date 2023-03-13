#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc, char *argv[]){
    ifstream inFile;
    ofstream outFile;
    int sum=0,num;
    double times=0;
    double avg;
    string line;
    inFile.open(argv[1]);
   // while(getline(inFile, str))
    while(getline(inFile,line)){
        int len=line.length();
        int k=line.find(":");
        int p=line.find("\n");
        if(k==len-1){
            times++;
        }
        else{
            num=stoi(line.substr(k+1,p-k));
            //cout<<num<<endl;
            sum+=num;
            times++;
        }  
    }
    //cout<<sum<<endl;
    //cout<<times<<endl;
    avg=sum/(times);
    outFile.open(argv[2]);
    outFile<<"The average is: "<<fixed<<setprecision(4)<<avg;
    inFile.close();
    outFile.close();
    return 0;
}
