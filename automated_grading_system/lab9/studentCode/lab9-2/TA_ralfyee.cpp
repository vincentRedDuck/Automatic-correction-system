#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

struct STUDENT
{
    string name;
    int score1;
    int score2;
    int score3;
    double average;
};

int main(int argc, char *argv[])
{
    STUDENT student[100];

    ifstream file;
    file.open(argv[2],ios::in);

    //extract student num
    string stringFromFile;
    getline(file,stringFromFile,'\n');
    int studentNum = 0;

    int numberOfStudent = 0;
    int studentDetail = 0;
    STUDENT tempStudent;
    while (!file.eof())
    {
        file>>stringFromFile;
        if(studentDetail == 0)
            tempStudent.name = stringFromFile;
        else if (studentDetail == 1)
            tempStudent.score1 = stoi(stringFromFile);
        else if (studentDetail == 2)
            tempStudent.score2 = stoi(stringFromFile);
        else
            tempStudent.score3 = stoi(stringFromFile);
        
        if(studentDetail == 3)
        {
            tempStudent.average = (tempStudent.score1 + tempStudent.score2 + tempStudent.score3)/3.0;
            student[studentNum] = tempStudent;
            studentNum++;
        }
        studentDetail ++;
        studentDetail = studentDetail % 4;
        
    }

    ofstream fileOutput;
    string outputFileName;
    if(argc<4)
    {
        outputFileName = argv[2];
        outputFileName = outputFileName + ".out";
    }
    else 
        outputFileName = argv[3];
    
    fileOutput.open(outputFileName,ios::out);

    if(strcmp(argv[1],"2") == 0)
    {
        for(int i =0; i<studentNum-1; i++)
        {
            for(int j=i+1; j<studentNum; j++)
            {
                if(strcmp(student[i].name.c_str(),student[j].name.c_str()) >0)
                {
                    STUDENT studentSwap = student[i];
                    student[i] = student[j];
                    student[j] = studentSwap;
                }
            }
        }
    }
        
    else
    {
        for(int i =0; i<studentNum-1; i++)
        {
            for(int j=i+1; j<studentNum; j++)
            {
                if(student[i].average > student[j].average)
                {
                    STUDENT studentSwap = student[i];
                    student[i] = student[j];
                    student[j] = studentSwap;
                }
            }
        }
    }

    

    for(int i =0; i<studentNum; i++)
    {
        // cout<<"name = "<<student[i].name<<" score1 = "<<student[i].score1<<" score 2 = "<<student[i].score2<<" score3 = "<< student[i].score3<<fixed<<setprecision(4)<<"average = "<<student[i].average<<endl;
        fileOutput<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<< student[i].score3<<fixed<<setprecision(4)<<" "<<student[i].average<<endl;
    }    




    return 0;
}
