#include<iostream>
using namespace std;
#include<fstream>
#include<sstream>
#include<string>

int main( int argc , char* argv[] ) {
    ifstream inFile;
    ofstream outFile;
    inFile.open(argv[1]);
    string line;
    outFile.open(argv[2]);
    if(outFile.fail()){
        cout << "fail!!"<<endl;
        return 1;
    }
    int count = 0;
    while (getline (inFile,line,'\n')) {
        cout << count++ << endl;
        string arr[100];
        int pos1 = line.find("/",8);
        int pos3 = line.find("?");
        int pos2 = line.rfind("/",pos3);
        stringstream ss(line.substr(pos3+1));//後面長度不寫=到最後
        // ss.clear();
        // ss.str(""); 
        // ss = line.substr(pos3+1);//後面長度不寫=到最後
        int i=0;
        while ( getline (ss,arr[i],'&') ) {
            i++;
        }
        outFile << "=====" << endl
            << "Domain name: "<< line.substr(line.find("//")+2,pos1-line.find("//")-2) << endl
            << "Method: " << line.substr(pos2+1,pos3-pos2-1) << endl;
        for (int k=0 ; k<i ; k++ ) {
            int pos = arr[k].find("=");
            if ( arr[k].substr(pos+1)!="" )
                outFile << arr[k].substr(0,pos) << ": " << arr[k].substr(pos+1) << endl;
        }
        outFile << endl;
    }     
    outFile << "=====" << endl; 
    return 0;
}
