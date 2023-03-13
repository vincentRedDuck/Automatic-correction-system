#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct sInfo
{
    string ID;
    string name;
    int scoreNum;
    int *score;
    double average;
};

void deleteInfo (sInfo*, int);

int main (int argc, char **argv)
{
    ifstream iFile(argv[1]);
    sInfo *test;
    int totalNum = 1;
    test = new sInfo[totalNum];
    while(iFile >> test[totalNum-1].ID >> test[totalNum-1].name >> test[totalNum-1].scoreNum)
    {
        test[totalNum-1].score = new int [test[totalNum-1].scoreNum];
        for (int j=0; j<test[totalNum-1].scoreNum; j++)
            iFile >> test[totalNum-1].score[j];
        sInfo *temp = new sInfo [totalNum];
        temp = test;
        test = NULL;
        totalNum++;
        test = new sInfo [totalNum];
        for (int i=0; i<totalNum-1; i++)
        {
            test[i].ID = temp[i].ID;
            test[i].name = temp[i].name;
            test[i].scoreNum = temp[i].scoreNum;
            test[i].score = new int [test[i].scoreNum];
            for(int j=0; j<temp[i].scoreNum; j++)
            {
                test[i].score[j] = temp[i].score[j];
            }
        }
        deleteInfo(temp, totalNum-1);
    }
    sInfo *temp = new sInfo [totalNum];
    for (int i=0; i<totalNum-1; i++)
    {
        temp[i].ID = test[i].ID;
        temp[i].name = test[i].name;
        temp[i].scoreNum = test[i].scoreNum;
        temp[i].score = new int [test[i].scoreNum];
        for(int j=0; j<temp[i].scoreNum; j++)
        {
            temp[i].score[j] = test[i].score[j];
        }
    }
    iFile.close();
    totalNum--;
    double aa = 0;
    for (int i=0; i<totalNum; i++)
    {
        if(test[i].scoreNum>10)
        {
            int key = 0;
            for (int j=1; j<test[i].scoreNum; j++)
                {
                    key = temp[i].score[j];
                    int k = j-1;
                    while (k>=0&&temp[i].score[k]<=key)
                    {
                        temp[i].score[k+1] = temp[i].score[k];
                        k--;
                    }
                    temp[i].score[k+1] = key;
                }
            test[i].average = 0.0;
            for (int j=0; j<10; j++)
                test[i].average += double(temp[i].score[j]);
            test[i].average /= 10.0;
            aa += test[i].average;
        }
        else
        {
            test[i].average = 0.0;
            for (int j=0; j<test[i].scoreNum; j++)
                test[i].average += double(temp[i].score[j]);
            test[i].average /= test[i].scoreNum;
            aa += test[i].average;
        }
    }
    aa = aa/totalNum;
    double sigma = 0.0;
    for (int i=0; i<totalNum; i++)
    {
        cout << test[i].ID << ' ' << test[i].name << ' ';
        for (int j=0; j<test[i].scoreNum; j++)
        {
            cout << test[i].score[j] << ' ';
        }
        cout << test[i].average << '\n';
        sigma += pow(abs(test[i].average-aa), 2.0);
    }
    sigma = sqrt(sigma/totalNum);
    cout << sigma << '\n';
    
    return 0;
}


void deleteInfo (sInfo* sI,int size)
{
    for (int i=0; i<size; i++)
    {
        delete [] sI[i].score;
        sI[i].score = NULL;
    }
    delete [] sI;
}

