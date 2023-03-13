#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main (int argc, char *argv[]) {
    
    char *infile = argv[1];
    char *outfile = argv[2];
    
    ifstream fin(infile);
    ofstream fout(outfile);
    
    int sum=0, count=0, i=0;
    int num[100]{0};
    double avr = 0.0;
    char ch;
    fin.get(ch);
    while (!fin.eof()) {
        if (ch==':') {
            if (isdigit(fin.peek())) {
                fin >> num[i++];
            } else {
                num[i++] = 0;
            }
        }
        fin.get(ch);
    }

    for (int j=0; j<100; j++) {
        sum += num[j];
    }
    avr = sum / (i*1.0);
    fout << "The average is: " << fixed <<setprecision(4) << avr;
//    if (fin.fail()) {
//        cout << "File \n"; //<< infile << " does not exist !!" << endl;
//        exit(1);
//    }
    
//    infile.close();
//    outfile.close();

    return 0;
}
