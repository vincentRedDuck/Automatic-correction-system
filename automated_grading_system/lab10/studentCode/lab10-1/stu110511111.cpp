#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string URL;
    string part;
    ifstream iFile(argv[1]);
    ofstream oFile(argv[2]);
    while (iFile >> URL)
    {
        oFile << "=====\n";
        URL.erase(0, URL.find("/")+2);
        oFile << "Domain name: " << URL.substr(0, URL.find("/")) << '\n';
        URL.erase(0, URL.find("/"));
        while (!URL.empty())
        {
            if (URL.find("/")!=string::npos)
            {
                URL.erase(0, URL.find("/")+1);
            }
            else
            {
                oFile << "Method: " << URL.substr(0, URL.find("?")) << '\n';
                URL.erase(0, URL.find("?")+1);
                while (!URL.empty())
                {
                    part = URL.substr(0, URL.find("=")) + ": ";
                    URL.erase(0, URL.find("=")+1);
                    if (URL.find("&")!=string::npos)
                    {
                        if (URL.find("&")>0)
                            oFile << part << URL.substr(0, URL.find("&")) << '\n';
                        URL.erase(0, URL.find("&")+1);
                    }
                    else if (URL.length()>0)
                    {
                        oFile << part << URL.substr(0, URL.length()) << '\n';
                        URL.erase(0, URL.length());
                    }
                }
            }
        }
    }
    oFile << "=====\n";

    iFile.close();
    oFile.close();
    return 0;
}
