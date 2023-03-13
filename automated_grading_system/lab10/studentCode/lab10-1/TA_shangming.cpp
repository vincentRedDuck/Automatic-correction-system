#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int _slash = 0, count = 0;
    bool flag = true, flag2;
    string title;
    fstream _in, _out;
    string _infile, _outfile, line, str, content, tmp;
    stringstream ss, ss2;
    _infile = argv[1];
    _outfile = argv[2];
    if (argc != 3)
    {
        cout << "Usage: ./ex10-1 [input file] [output file]" << endl;
        return 1;
    }
    _in.open(_infile, ios::in);
    if (!_in)
    {
        cout << "Cannot find input file." << endl;
        return 1;
    }
    _out.open(_outfile, ios::out);
    while (getline(_in, line))
    {
        int pos = line.find('/');
        int pos2 = line.find('/', pos + 2);
        // cout << pos << " " << pos2 << endl;
        tmp = line.substr(pos + 2, pos2 - pos - 2);
        // cout << tmp << endl;
        _out << "=====" << endl;
        _out << "Domain name: " << tmp << endl;
        pos = line.find("?");
        pos2 = line.rfind('/', pos);
        tmp = line.substr(pos2 + 1, pos - pos2 - 1);
        _out << "Method: " << tmp << endl;
        line.erase(0, pos + 1);
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == 38)
                line[i] = ' ';
        }
        ss << line;
        while (ss >> str)
        {
            if (str[str.size() - 1] != '=')
            {
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] == '=')
                        str[i] = ' ';
                }
                ss2 << str;
                ss2 >> tmp;
                // if (tmp == "Domain")
                // {
                //     _out << "Domain name: ";
                //     ss2 >> tmp;
                //     ss2 >> tmp;
                //     _out << tmp << endl;
                // }
                {
                    _out << tmp << ": ";
                    ss2 >> tmp;
                    _out << tmp << endl;
                }
                ss2.clear();
            }
        }
        ss.str("");
        ss.clear();
    }
    _out << "=====" << endl;
    _in.close();
    _out.close();
    return 0;
}