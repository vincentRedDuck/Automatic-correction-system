#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    stringstream ss;
    string line;
    while(getline(fin,line))
    {
        string http;
        fout << "=====" << endl;
        http = line;
        int a = http.find('/');
        http.erase(0,a+2);
        int i = 0;
        string dom,meth;
        while(http[i]!='/')
        {
            ss << http[i];
            i++;
        }
        ss >> dom;
        fout << "Domain name: " << dom << endl;
        ss.str("");
        ss.clear();
        i=i+1;
        while(http[i]!='?')
        {
            if(http[i]=='/')
            {
                ss.str("");
                ss.clear();
            }
            else
            {
                ss << http[i];
            }
            i++;
            
        }
        ss >> meth;
        fout << "Method: " << meth << endl;
        ss.str("");
        ss.clear();
        int j = http.find('?');
        http.erase(0,j+1);
        int k = 0;
        while(http[k]!='\0')
        {
            if(http[k]=='=')
            {
                if(http[k+1]=='\0')
                {
                    ss.str("");
                    ss.clear();
                    break;
                }
                else if(http[k+1]=='&')
                {
                    ss.str("");
                    ss.clear();
                    k+=2;
                }
                else
                {
                    fout << ss.str() << ": ";
                    ss.str("");
                    ss.clear();
                    k++;
                }
            }
            else if(http[k]=='&')
            {
                fout << ss.str() << endl;
                ss.str("");
                ss.clear();
                k++;
            }
            else
            {
                ss << http[k];
                k++;
            }
        }
        if(http[k+1]!='\0')
        {
            fout << ss.str() << endl;
            ss.str("");
            ss.clear();
        }

    }
    fout << "=====" << endl;
    return 0;
}
