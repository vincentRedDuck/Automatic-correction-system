#include<iostream>
using namespace std;
#include<fstream>
#include<iomanip>

int main(int argc , char* argv[]) {
    ifstream inFile;
    ofstream outFile;
    inFile.open(argv[1]);
    string line; 
    int sum = 0;
    int score;
    double count=0;
    while (getline(inFile, line)) {
        int pos1 = line.find(":");
        int pos2 = line.find("\n");
        string num = line.substr (pos1+1 , pos2-pos1);
        cout << num;
        if (num == "") score = 0; 
        else score = stoi(num);
        sum += score;
        count++;
    }
    double avg = sum/count;
    outFile.open(argv[2]);
    outFile << "The average is: " << fixed << setprecision(4) << avg;
    return 0;
}
