#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 scores average
};


int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    string line;
    int num=0;
    while(getline(fin,line))
    {
        num++;
    }
    line.clear();
    fin.close();

    ifstream fin1(argv[1]);
    student stu[num];
    int n=0;
    while(getline(fin1,line))
    {
        stringstream ss(line);
        ss >> stu[n].ID >> stu[n].name >> stu[n].num_score ;
        cout << stu[n].ID << " " <<stu[n].name << " "  ;
        
        stu[n].score = new int[20];
        for(int i=0; i< stu[n].num_score; i++)
        {
            ss >> stu[n].score[i] ;
        }
        for(int i=0; i<stu[n].num_score; i++)
            cout << stu[n].score[i] << " ";

        if(stu[n].num_score>10)
        {
            for (int i = 1; i < stu[n].num_score; i++) 
            {
                int key = stu[n].score[i];
                int j = i - 1;
                while (key < stu[n].score[j] && j >= 0) 
                {
                    stu[n].score[j+1] = stu[n].score[j];
                    j--;
                }
                stu[n].score[j+1] = key;
            }
            int total = 0;
            for(int i=(stu[n].num_score-10); i<stu[n].num_score; i++) 
            {
                total = total + stu[n].score[i];
            }      
            stu[n].average = total/(10.0);
        }
        else
        {
            int total = 0;
            for(int i=0; i<stu[n].num_score; i++)
            {
                total = total + stu[n].score[i];
            }
            stu[n].average = total/(stu[n].num_score*1.0);
        }
        cout << stu[n].average ;

           
        
        cout<< endl;
        n++;
    }
    
    double sum_av =0;
    for(int i=0;i<num ;i++ )
    {
        sum_av = sum_av + stu[i].average;
    }
    double mu = sum_av/num;
    double sig = 0;
    for(int i=0;i<num ;i++ )
    {
        sig += (stu[i].average-mu)*(stu[i].average-mu);
    }
    cout << sqrt(sig/num) << endl;
    return 0;
}
