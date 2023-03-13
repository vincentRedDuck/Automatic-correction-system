#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){
    ifstream iFile(argv[1]);
    ofstream oFile(argv[2]);

    string URL;
    oFile<<"====="<<endl;
    while(getline(iFile, URL)){
        int pos = URL.find("//");
        int pos2 = URL.substr(pos+2).find("/");
        oFile<<"Domain name: "<<URL.substr(pos+2, pos2)<<endl;

        pos = URL.find("?");
        pos2 = URL.substr(0,pos).find_last_of("/");
        oFile<<"Method: "<<URL.substr(pos2+1, pos-pos2-1)<<endl;

        stringstream ss(URL.substr(pos+1, URL.length()-pos-1));
        string run;
        while(getline(ss, run, '&')){
            int p = run.find("=");

            if(run.length() == (p+1))
                continue;

            oFile<<run.substr(0,p)<<": "<<run.substr(p+1, run.length()-p-1)<<endl;
            run.clear();
        }
        oFile<<"====="<<endl;
    }
    iFile.close();
    oFile.close();

    return 0;
}
