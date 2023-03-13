#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    double score;
    int i=0;
    double sum=0;
    while(!fin.eof())
    {
        fin.ignore(256,':');
        if(fin.peek()<='9'&&fin.peek()>='0')
        {fin>>score;sum+=score;}
        else
        fin.ignore(1,'\n');
        i++;
    }
    sum=sum/(i-1);
    fout<<"The average is: "<<setprecision(4)<<fixed<<sum;
    fout.close();
    fin.close();
    return 0;
}
