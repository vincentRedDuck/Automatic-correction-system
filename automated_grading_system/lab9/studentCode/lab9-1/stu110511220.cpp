#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int main (int argc, char *argv[]) {
    ifstream inFile(argv[1]);
    ofstream outfile(argv[2]);
    double avg = 0;
    double num = 0;
    string textline;
    while(getline(inFile,textline,'\n')) {
        string NUM;
        if(textline[textline.find(':')+1]==' ') {
            avg += 0;
            num++;
        }
        else {
            for(int i=textline.find(':')+1;i<=textline.length();i++) {
                NUM += textline[i];
            }
            avg += atoi(NUM.c_str());
            num++;
        }
    }
    avg /= num;
    outfile << fixed << setprecision(4) <<"The average is: " << avg;

    inFile.close();
    return 0;
}
