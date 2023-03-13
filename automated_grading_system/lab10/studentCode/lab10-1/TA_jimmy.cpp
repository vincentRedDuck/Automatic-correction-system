#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){
    /*if(argc != 3){
        cerr<<"Usage: ./lab12-1 [inputfile] [outputfile]"<<endl;
        return 1;
    }*/
    ifstream iFile(argv[1]);
    ofstream oFile(argv[2]);

    string URL;
    oFile<<"====="<<endl;
    while(getline(iFile, URL)){
        int pos = URL.find("?");
        //cout<<pos<<endl;
        string subURL = URL.substr(0,pos);
        int pos2 = subURL.find_last_of("/");
        //cout<<subURL<<endl;
        //cout<<pos2<<endl;
        oFile<<"Method: "<<subURL.substr(pos2+1, subURL.length()-pos2-1)<<endl;
        stringstream ss(URL.substr(pos+1, URL.length()-pos-1));
        string sub;
        while(getline(ss, sub, '&')){
            //cout<<sub<<endl;
            int p = sub.find("=");
            //cout<<p<<" "<<sub.length()<<endl;
            if(sub.length() == (p+1))
                continue;
            oFile<<sub.substr(0,p)<<": "<<sub.substr(p+1, sub.length()-p-1)<<endl;
            sub.clear();
        }
        oFile<<"====="<<endl;
    }

    iFile.close();
    oFile.close();

    return 0;
}
