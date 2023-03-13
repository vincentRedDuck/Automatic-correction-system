#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

struct Student
{
    int ID;
    string name;
    int *score;
    int num_score;
    double average;
};
void DisplayInformation(Student *Stu, int num_Stu, int num_zero)
{
    for (int i = 0; i < num_Stu; i++)
    {
        for (int j = 0; j < num_zero; j++)
            cout << "0";
        cout << Stu[i].ID << " ";
        cout << Stu[i].name << " ";
        for (int j = 0; j < Stu[i].num_score; j++)
            cout << Stu[i].score[j] << " ";
        cout << Stu[i].average << endl;
    }
}
void Sorting(Student *Stu)
{
    for (int j = 0; j < Stu->num_score - 1; j++)
    {
        for (int k = 0; k < Stu->num_score - 1 - j; k++)
        {
            if (Stu->score[k] < Stu->score[k + 1])
            {
                int tmp = Stu->score[k];
                Stu->score[k] = Stu->score[k + 1];
                Stu->score[k + 1] = tmp;
            }
        }
    }
}
int *Sorting2(Student Stu)
{
    int *tmp = new int[Stu.num_score];
    copy(Stu.score, Stu.score + Stu.num_score, tmp);
    for (int j = 0; j < Stu.num_score - 1; j++)
    {
        for (int k = 0; k < Stu.num_score - 1 - j; k++)
        {
            if (tmp[k] < tmp[k + 1])
            {
                int t = tmp[k];
                tmp[k] = tmp[k + 1];
                tmp[k + 1] = t;
            }
        }
    }
    return tmp;
}

void CalculateAvg(Student *Stu, int num_Stu)
{
    double total = 0.0;
    for (int i = 0; i < num_Stu; i++)
    {
        if (Stu[i].num_score <= 10)
        {
            for (int j = 0; j < Stu[i].num_score; j++)
                total += Stu[i].score[j];
            Stu[i].average = total / double(Stu[i].num_score);
        }
        else
        {
            int *tmp = Sorting2(Stu[i]);
            for (int j = 0; j < 10; j++)
                total += double(tmp[j]);
            delete[] tmp;
            Stu[i].average = total / 10.0;
        }
        total = 0.0;
    }
}

double CalculateSD(Student *Stu, int num_Stu)
{
    double total = 0.0, SD, avg;
    for (int i = 0; i < num_Stu; i++)
        total += Stu[i].average;
    avg = total / double(num_Stu);
    for (int i = 0; i < num_Stu; i++)
        SD += pow(Stu[i].average - avg, 2);
    SD = sqrt(SD / double(num_Stu));
    return SD;
}
int main(int argc, char *argv[])
{
    int num_Stu = 0, idx = 0, times = 0, jdx = 0, num_zero;
    double SD;
    string inFile, line, str;
    fstream _in;
    stringstream ss;
    inFile = argv[1];
    _in.open(inFile, ios::in);
    while (getline(_in, line))
        num_Stu++;
    _in.close();
    _in.open(inFile, ios::in);
    Student *Stu = new Student[num_Stu];
    while (idx < num_Stu)
    {
        getline(_in, line);
        ss << line;
        while (ss >> str)
        {
            switch (times)
            {
            case 0:
            {
                num_zero = str.length() - to_string(stoi(str)).length();
                Stu[idx].ID = stoi(str);
            }
            break;
            case 1:
                Stu[idx].name = str;
                break;
            case 2:
            {
                Stu[idx].num_score = stoi(str);
                Stu[idx].score = new int[Stu[idx].num_score];
            }
            break;
            default:
            {
                Stu[idx].score[jdx] = stoi(str);
                jdx++;
            }
            break;
            }
            times++;
        }
        jdx = 0;
        times = 0;
        ss.str("");
        ss.clear();
        idx++;
    }
    CalculateAvg(Stu, num_Stu);
    DisplayInformation(Stu, num_Stu, num_zero);
    SD = CalculateSD(Stu, num_Stu);
    cout << SD << endl;
    return 0;
}
