#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    double num,sum=0,count = 0;
    char ch;
    while (1) {
        fin.ignore(10,':');
        ch = fin.peek();
        if (fin.eof()) {
            break;
        }
        else if (ch == '\n') {
            count++;
            continue;
        }
        else {
            fin >> num;
            sum += num;
            count++;
        }
    }
    fout << "The average is: " << fixed << setprecision(4) << sum/count ;
    fin.close();
    fout.close();
    return 0;
}
