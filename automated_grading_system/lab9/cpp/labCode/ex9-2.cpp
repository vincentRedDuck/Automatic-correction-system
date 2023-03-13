#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Studata
{
    string stu;
    int s1;
    int s2;
    int s3;
    double avg;
};
int main(int argc, char *argv[])
{
    Studata stus[999];
    string outname;
    if (argc == 3)
    {
        outname = string(argv[2]) + ".out";
    }
    else
    {
        outname = argv[3];
    }
    int choice = atoi(argv[1]);
    // cout << outname << endl;

    ifstream infile;
    infile.open(argv[2]);
    if (!infile)
    {
        cout << "Cannot open file" << endl;
        exit(1);
    }
    double total = 0;

    int num = 0;
    infile >> num;
    Studata tmpdata;

    for (int i = 0; i < num; i++)
    {
        infile >> tmpdata.stu >> tmpdata.s1 >> tmpdata.s2 >> tmpdata.s3;
        // cout << tmpdata.stu << ", " << tmpdata.s1 << ", " << tmpdata.s2 << ", " << tmpdata.s3 << endl;
        total = (tmpdata.s1 + tmpdata.s2 + tmpdata.s3) / 3.0;
        tmpdata.avg = total;
        stus[i] = tmpdata;
        // cout << fixed << setprecision(4) << tmpdata.avg << endl;
    }

    infile.close();

    // cout << fixed << setprecision(4) << total / num << endl;

    ofstream outfile;
    outfile.open(outname);
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (choice == 2)
            {
                if (stus[j].stu > stus[j + 1].stu)
                {
                    tmpdata = stus[j];
                    stus[j] = stus[j + 1];
                    stus[j + 1] = tmpdata;
                }
            }
            else
            {
                if (stus[j].avg > stus[j + 1].avg)
                {
                    // cout << stus[j].avg << ">" << stus[j + 1].avg << endl;

                    tmpdata = stus[j];
                    stus[j] = stus[j + 1];
                    stus[j + 1] = tmpdata;
                }
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        outfile << stus[i].stu << " " << stus[i].s1 << " " << stus[i].s2 << " " << stus[i].s3 << " " << fixed << setprecision(4) << stus[i].avg << endl;
    }

    outfile.close();

    return 0;
}
