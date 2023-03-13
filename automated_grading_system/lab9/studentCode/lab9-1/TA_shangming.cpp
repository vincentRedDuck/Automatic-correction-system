#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: ./ex9-1 <input_file> <output_file>" << endl;
        return 1;
    }
    fstream _in, _out;
    string line;
    double sum = 0.0;
    int count = 0;
    _in.open(argv[1], ios::in);
    if (!_in)
        cout << "no input file" << endl;
    else
    {
        while (getline(_in, line))
        {
            int pos = line.find(":");
            int len = strlen(line.c_str());
            if (line[len - 1] != ':')
                sum += stod(line.substr(pos + 1, len - pos - 1));
            count++;
        }
        _in.close();
        _out.open(argv[2], ios::out);
        _out << "The average is: ";
        _out << fixed << setprecision(4) << double(sum / count);
        _out.close();
    }
    return 0;
}