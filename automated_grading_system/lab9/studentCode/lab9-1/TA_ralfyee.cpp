#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int scoreExtract(string stringFromFile )
{
    int score = 0;
    bool start_extract = false;
    for(int i =0; i<stringFromFile.length(); i++)
    {
        if(start_extract)
            score = score * 10 + stringFromFile[i] - '0' ;
        
        if (stringFromFile[i] == ':')
            start_extract = true;
            
    }
    return score;
}

int main(int argc, char *argv[])
{

    fstream file;
    file.open(argv[1], ios::in);
    
    string temp;
    double average = 0;
    int times = 0;
    while(getline(file,temp,'\n'))
    {
        times++;
        average = average + scoreExtract(temp);
    }
    file.close();

    file.open(argv[2],ios::out);
    file<<fixed<<setprecision(4)<<"The average is: "<<average/times;

    return 0;
}
