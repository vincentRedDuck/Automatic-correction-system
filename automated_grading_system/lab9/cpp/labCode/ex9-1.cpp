#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    if (!infile)
    {
        cout << "Cannot open file" << endl;
        exit(1);
    }
    double total = 0;
    int num = 0;
    string str;
    while (getline(infile, str))
    {
        // cout << str << endl;
        str.erase(0, str.find(":") + 1);

        if (str.length() == 0)
        {
            total += 0;
            // cout << "0" << endl;
            num += 1;
            continue;
        }

        str.erase(0, str.find(":") + 1);
        // cout << stoi(str) << endl;
        total += stoi(str);
        num += 1;
    }
    infile.close();

    // cout << fixed << setprecision(4) << total / num << endl;
    ofstream outfile;
    outfile.open(argv[2]);
    outfile << "The average is: " << fixed << setprecision(4) << total / num;
    outfile.close();

    return 0;
}
