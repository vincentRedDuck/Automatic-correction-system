#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main (int argc, char *argv[])
{
    char *iFileName = argv[1];
    char *oFileName = argv[2];
    ifstream iFile;
    ofstream oFile;
    iFile.open(iFileName);
    oFile.open(oFileName);
    int count = 0;
    float total = 0;
    string textLine;
    while (getline(iFile, textLine, '\n'))
    {
        textLine.erase(0, textLine.find(":")+1);
        if (textLine=="")
        {
        }
        else
        {
            for (int i=0; i<textLine.length(); i++)
            {
                total += int(textLine[i]-48)*pow(10, textLine.length()-1-i);
            }
        }
        count++;
    }
    oFile << fixed << setprecision(4) << "The average is: " << total/count;
    
    iFile.close();
    oFile.close();
    return 0;
}
