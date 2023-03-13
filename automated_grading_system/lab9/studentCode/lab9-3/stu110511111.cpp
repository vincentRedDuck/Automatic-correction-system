#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct morseCode{
    char alpha;
    string code;
};

int main (int argc, char **argv)
{
    ifstream iFile("code.txt");
    morseCode data[36];
    for (int i=0; i<36; i++)
        iFile >> data[i].alpha >> data[i].code;
    iFile.close();
    iFile.open(argv[1]);
    ofstream oFile(argv[2]);
    string mode = argv[3];
    if (mode == "e")
    {
        string line;
        char c;
        stringstream ss;
        while (getline(iFile, line, '\n'))
        {
            ss.str(line);
            while (ss.get(c))
            {
                if (c==' ')
                    oFile << "    ";
                else
                {
                    for (int i=0; i<36; i++)
                    {
                        if (c==data[i].alpha)
                        {
                            oFile << data[i].code;
                        }
                    }
                    if (!ss.eof())
                        oFile << "   ";
                }
            }
            ss.str("");
            ss.clear();
            oFile << '\n';
        }
    }
    else
    {
        string line;
        stringstream ss;
        char c;
        while (getline(iFile, line, '\n'))
        {
            ss.str(line);
            while (ss.get(c))
            {
                ss.putback(c);
                if(ss.peek()==' ')
                {
                    for (int i=0; i<3; i++)
                        ss.get(c);
                    if(ss.peek()==' ')
                    {
                        oFile << ' ';
                        for (int i=0; i<4; i++)
                            ss.get(c);
                    }
                }
                else
                {
                    line = ("");
                    for (int i=0; i<5; i++)
                    {
                        if(ss.peek()!='.'&&ss.peek()!='-')
                            continue;
                        ss.get(c);
                        line += c;
                    }
                    for (int i=0; i<36; i++)
                        if (line==data[i].code)
                            oFile << data[i].alpha;
                }
            }
            ss.str("");
            ss.clear();
            oFile << '\n';
        }
    }
    iFile.close();
    oFile.close();

    return 0;
}
