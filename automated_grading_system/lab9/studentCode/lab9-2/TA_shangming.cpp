#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student
{
    string name;
    int grade[3];
    double avg;
};

void Sort(int, int, Student[]);

int main(int argc, char *argv[])
{
    stringstream ss;
    fstream _in, _out;
    string line, data, outfile;
    if (argc == 3)
        outfile = string(argv[2]) + ".out";
    else
        outfile = argv[3];
    int option;
    option = atoi(argv[1]);
    int count, i = 0, j = 0;

    _in.open(argv[2], ios::in);
    if (!_in)
    {
        cout << "No input file" << endl;
        exit(1);
    }
    getline(_in, line);
    ss << line;
    ss >> data;
    ss.clear();
    count = stoi(data);
    // cout << count << endl;
    Student Stu[count];
    while (getline(_in, line))
    {
        ss << line;
        ss >> data;
        // cout << data << endl;
        Stu[i].name = data;
        while (ss >> data)
        {
            // cout << data << endl;
            Stu[i].grade[j] = stoi(data);
            j++;
        }
        j = 0;
        i++;
        ss.clear();
    }
    _in.close();
    for (int i = 0; i < count; i++)
    {
        Stu[i].avg = 0.0;
        for (int j = 0; j < 3; j++)
            Stu[i].avg += Stu[i].grade[j];
        Stu[i].avg /= 3.0;
    }
    // for (int i = 0; i < count; i++)
    //     cout << Stu[i].avg << endl;
    Sort(option, count, Stu);
    // cout << strlen(Stu) << endl;
    // for (int x = 0; x < count; x++)
    // {
    //     cout << Stu[x].name << " ";
    //     for (int y = 0; y < 3; y++)
    //         cout << Stu[x].grade[y] << " ";
    //     cout << fixed << setprecision(4) << Stu[x].avg << endl;
    // }
    _out.open(outfile, ios::out);
    for (int x = 0; x < count; x++)
    {
        _out << Stu[x].name << " ";
        for (int y = 0; y < 3; y++)
            _out << Stu[x].grade[y] << " ";
        _out << fixed << setprecision(4) << Stu[x].avg << endl;
    }
    _out.close();
}

void Sort(int option, int size, Student stu[])
{
    if (option == 1)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (stu[j].avg > stu[j + 1].avg)
                {
                    Student tmp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = tmp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (stu[j].name[0] > stu[j + 1].name[0])
                {
                    Student tmp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = tmp;
                }
            }
        }
    }
}