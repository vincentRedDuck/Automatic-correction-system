#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

void read(float &avg, float &count, string open){
    int len, i; 
    float num;
    string temp;
    len = open.length();
    i = open.find(':');
    i++;
    if(len - i <= 1){
        avg += 0.0;
    }
    else{
        temp = open.substr(i, len-i);
        num = stof(temp);
        avg += num;
    }
    count += 1.0;
}

int main(int argc, char *argv[]){
    ifstream file1;
    ofstream file2;
    float avg = 0.0, count = 1.0;
    string open, rfile = argv[1], wfile = argv[2];
    file1.open(rfile);
    while(file1 >> open){
        read(avg, count, open);
    }
    count -= 1.0;
    avg /= count;
    file2.open(wfile, ios::out);
    file2 << "The average is: " << fixed << setprecision(4) << avg;
    file1.close();
    file2.close();
    return 0;
}
