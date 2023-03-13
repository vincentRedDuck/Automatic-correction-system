//File: lab9-2-1.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>


using namespace std;

int main(int argc, char *argv[]){
   
    string textline;    

    ifstream inFile;
    ofstream outFile;
 
    string filename = argv[1];
    string filename2 = argv[2];

    ifstream in_file(filename);    
    ofstream out_file(filename2);
    //getline(in_file,textline);
    //cout <<"Read: "<<textline;
    
    double sum =0.0;
    int count = 0;
    while(getline(in_file,textline) ){
                
        int pos = textline.find(":");
        int len = textline.length();
        double score = 0; 
        //double score =  stod(textline.substr(pos+1,len-pos-1));
         
        //cout <<"Read: "<<textline;
        //cout <<"TL:"<<len/*<<textline.length()*/<<"pos:"<<pos<<endl;
                
        
        if(pos+1==len){
            sum = sum +0;
            count +=1;
        }
        else{
            score =  stod(textline.substr(pos+1,len-pos-1));
       
            sum =sum + score;
            count +=1;
        }
        //cout <<"score:"<<score;

    }    

    out_file<<"The average is: "<<fixed<<setprecision(4)<<sum/count;
    

    return 0;
}
