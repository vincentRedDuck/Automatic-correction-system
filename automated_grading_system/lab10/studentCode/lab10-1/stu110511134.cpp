#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>


using namespace std;

int main(int argc, char *argv[]){

    string textline;

    //ifstream inFile;
    //ofstream outFile;

    string filename = argv[1];
    string filename2 = argv[2];

    ifstream in_file(filename);
    ofstream out_file(filename2);
    out_file <<"====="<<endl;
    while(getline(in_file,textline) ){

        int pos = textline.find(":");//position of :// /
        int pos2 = textline.find("?");
        
        int pos1_5 =textline.find("/",pos+3);
        //int pos2 = textline.find("?");
        int pos3 = textline.find_last_of("/",pos2);
        int len = textline.length();

        out_file <<"Domain name: "<<textline.substr(pos+3,pos1_5-pos-3)<<endl;
        out_file <<"Method: "     <<textline.substr(pos3+1,pos2-pos3-1)<<endl;
        
        stringstream newtxt;
        string newstr;
        newtxt << textline.substr(pos2+1,len-pos2-1);
        
        while( getline(newtxt,newstr,'&') ){
            
            int pos4 = newstr.find("=");
            int len2 = newstr.length();
            if(pos4+1 !=len2)
                out_file << newstr.substr(0,pos4)<<": "<<newstr.substr(pos4+1,len2-pos4-1) <<endl;
            else if(pos4+1 == len2)
                continue;
        }
        out_file <<"====="<<endl;
    }    
    
    
    

    return 0;
}
