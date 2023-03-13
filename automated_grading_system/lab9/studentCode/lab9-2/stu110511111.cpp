#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct sInfo{
    string name;
    int scoreA;
    int scoreB;
    int scoreC;
    double average;
};

int main (int argc, char **argv)
{
    ifstream iFile(argv[2]);
    string oF;
    bool insert = false;
    if (argc==4)
        oF = argv[3];
    else if(argc==3)
    {
        oF = argv[2];
        oF = oF + ".out";
        insert = true;
    }
    int state = (atoi(argv[1]));
    ofstream oFile(oF);
    int stuNum = 0;
    iFile >> stuNum;
    int const cStuNum = stuNum;
    sInfo classA[cStuNum];
    for (int i=0; i<cStuNum; i++)
    {
        iFile >> classA[i].name  >> classA[i].scoreA >> classA[i].scoreB >> classA[i].scoreC;
        classA[i].average = (classA[i].scoreA + classA[i].scoreB + classA[i].scoreC)/3.0;
    }
    iFile.close();
    if (insert==true)
    {
        if (state==1)
        {
            for (int i=1; i<cStuNum; i++)
            {
                sInfo key = classA[i];
                int j = i-1;
                while (j>=0&&classA[j].average>=key.average)
                {
                    classA[j+1] = classA[j];
                    j--;
                }
                classA[j+1] = key;
            }
        }
        else
        {
            for (int i=1; i<cStuNum; i++)
            {
                sInfo key = classA[i];
                int j = i-1;
                while (j>=0&&strcmp(classA[j].name.c_str(), key.name.c_str())>0)
                {
                    classA[j+1] = classA[j];
                    j--;
                }
               classA[j+1] = key;
            }
        }
    }
    else
    {
        if (state==1)
            {
                for (int i=1; i<cStuNum; i++)
                {
                    sInfo key = classA[i];
                    int j = i-1;
                    while (j>=0&&classA[j].average>=key.average)
                    {
                        classA[j+1] = classA[j];
                        j--;
                    }
                    classA[j+1] = key;
                }
            }
        else
            {
                for (int i=1; i<cStuNum; i++)
                {
                    sInfo key = classA[i];
                    int j = i-1;
                    while (j>=0&&strcmp(classA[j].name.c_str(), key.name.c_str())>0)
                    {
                        classA[j+1] = classA[j];
                        j--;
                    }
                classA[j+1] = key;
                }
            }
    }
    for (int i=0; i<cStuNum; i++)
    {
        oFile << classA[i].name << ' ' << classA[i].scoreA << ' ' << classA[i].scoreB << ' ' << classA[i].scoreC << ' ';
        oFile << fixed << setprecision(4)<< classA[i].average <<'\n';
    }
    oFile.close();

    return 0;
}
