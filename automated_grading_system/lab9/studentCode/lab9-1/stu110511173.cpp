#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream inFile(argv[1]);     
    string textline;
    double tol=0;
    int co = 0;
    while (getline(inFile,textline,'\n'))
    {  
        textline.erase(0,textline.find(":")+1);
        if(textline=="")
            tol += 0;
        else
            tol += stoi(textline);
        // cout << textline << endl;
        co++;
    }   
    tol = tol*1.0/co;
    //cout << tol << endl;
    ofstream outFile(argv[2]);
    outFile << "The average is: " << fixed << setprecision(4)<< tol ;
    outFile.close();
    inFile.close(); 
    return 0;
}
