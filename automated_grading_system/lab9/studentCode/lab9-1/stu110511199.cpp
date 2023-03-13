#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main(int argc, char *argv[]) {
    string filename1 = argv[1];
    string filename2 = argv[2];
    ofstream out_file;
    ifstream in_file;
    in_file.open(filename1.c_str());
    if (in_file.fail()) {
        cout << "File " << filename1 << " does not exist !!" << endl;
        exit(1);
    }
    int num;
    int count = 0;
    int sum=0;
    char ch ;
    char word[100];
    ch = in_file.peek();
    while (!in_file.eof()) {
        if ((ch>='0')&&(ch<='9')) {
            in_file >> num;
            sum += num;
        } else {
            if (ch==':')  count ++;
            in_file.get(ch);
            }
        ch = in_file.peek();
    }
    out_file.open(filename2.c_str());
    out_file << "The average is: " << setprecision(4) << fixed << 1.0*sum/count;
    in_file.close();
    out_file.close();
    
    return 0;

}
