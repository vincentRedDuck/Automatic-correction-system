#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail()){
        cout << "Fail";
    }
    char ch;
    int count=0,k=0;
    double t = 0;
    double score[10]={0};
    string str,str2;
    while(getline(in_file, str)){
        for(int i=0; str[i]!=':'; i++){
            count++;
        }
        str.erase(0, str.find(":")+1);
        cout << str << endl;
        if(str == ""){
            t += 0;
        }
        else{
            t += stoi(str);
        }
       //  str2 = str.substr(count+1);
        // count = 0;
        // score[k] = atoi(str2.c_str());
        k++;
    }
    in_file.close();
    ofstream out_file;
    out_file.open(argv[2], ios::trunc);
    out_file << "The average is: " << fixed << setprecision(4) << t/k;
    out_file.close();
    return 0;
}
