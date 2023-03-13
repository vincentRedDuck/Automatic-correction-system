#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Pokemon
{
    string number;
    string name;
    bool flag = true;
};

int main(int argc, char *argv[])
{
    Pokemon Ans[1000];
    Pokemon Pok[493];
    int count = 0, num, size = 0;
    stringstream ss;
    fstream _in, _out;
    string infile1, infile2, outfile1, outfile2, line, str;
    if (argc != 5)
    {
        cout << "Usage: ./ex10-2 [file1] [file2] [file3] [file4]" << endl;
        return 1;
    }
    infile1 = argv[1];
    outfile1 = argv[2];
    infile2 = argv[3];
    outfile2 = argv[4];
    _in.open(infile1, ios::in);
    _out.open(outfile1, ios::out);
    while (getline(_in, line))
    {
        ss << line;
        while (ss >> str)
        {
            count++;
            if (count == 1)
            {
                num = stoi(str);
                Pok[num - 1].number = str;
            }
            else if (count == 3)
                Pok[num - 1].name = str;
            if (count == 1 || count == 3 || count == 4)
                _out << str << " ";
        }
        _out << endl;
        count = 0;
        ss.str("");
        ss.clear();
    }
    _in.close();
    _out.close();
    _in.open(infile2, ios::in);
    _out.open(outfile2, ios::out);
    while (getline(_in, line))
    {
        ss << line;
        while (ss >> str)
        {
            int x = str[0];
            if (x > 64 && x < 91)
            {
                for (int i = 0; i < 493; i++)
                {
                    if (str.compare(Pok[i].name) == 0)
                    {
                        // cout << Pok[i].number << " ";
                        // cout << Pok[i].name << endl;
                        Ans[size].number = Pok[i].number;
                        Ans[size].name = Pok[i].name;
                        size++;
                    }
                }
            }
            else
            {
                for (int i = 0; i < 493; i++)
                {
                    if (stoi(str) == stoi(Pok[i].number))
                    {
                        // cout << Pok[i].number << " ";
                        // cout << Pok[i].name << endl;
                        Ans[size].number = Pok[i].number;
                        Ans[size].name = Pok[i].name;
                        size++;
                    }
                }
            }
            // int x = str[0];
            // cout << x << endl;
        }
        // for (int i = 0; i < size; i++)
        // {
        //     cout << Ans[i].number << " ";
        //     cout << Ans[i].name << endl;
        // }
        // cout << size << endl;
        ss.str("");
        ss.clear();
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (stoi(Ans[j].number) > stoi(Ans[j + 1].number))
            {
                Pokemon tmp = Ans[j];
                Ans[j] = Ans[j + 1];
                Ans[j + 1] = tmp;
            }
        }
    }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << Ans[i].number << " ";
    //     cout << Ans[i].name << endl;
    // }
    for (int i = 0; i < size; i++)
    {
        if (Ans[i].number == Ans[i + 1].number)
            continue;
        else
            _out << stoi(Ans[i].number) << " " << Ans[i].name << endl;
    }
    _in.close();
    _out.close();
    return 0;
}
