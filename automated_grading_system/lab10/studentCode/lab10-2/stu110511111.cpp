#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

struct poke
{
    string code;
    string jname;
    string ename;
    string cname;
    bool get;
};

using namespace std;

int main(int argc, char *argv[])
{
    ifstream iFile(argv[1]);
    ofstream oFile(argv[2]);
    poke fn[493];
    string temp;
    stringstream ssfn;
    for (int i=0; i<493; i++)
    {
        getline(iFile, temp, '\n');
        ssfn.str(temp);
        ssfn >> fn[i].code >> fn[i].jname >> fn[i].ename >> fn[i].cname;
        if (fn[i].cname.find(" ")!=string::npos)
        {
            fn[i].cname.erase(fn[i].cname.find(" "),fn[i].cname.length()-fn[i].cname.find(" "));
        }
        oFile << fn[i].code << " " << fn[i].ename << " " << fn[i].cname << '\n';
        fn[i].get = false;
    }
    iFile.close();
    oFile.close();
    iFile.open(argv[3]);
    oFile.open(argv[4]);
    while (iFile >> temp)
    {
        if (isdigit(temp[0]))
        {
            fn[atoi(temp.c_str())-1].get = true;
            temp = "\0";
        }
        else
        {
            for (int i=0; i<493; i++)
            {
                if (fn[i].ename == temp)
                {
                    fn[i].get = true;
                    continue;
                }
            }
            temp = "\0";
        }
    }
    for (int i=0; i<493; i++)
    {
        if (fn[i].get == true)
        {
            oFile << atoi(fn[i].code.c_str()) << ' ' << fn[i].ename << '\n';
        }
    }
    iFile.close();
    oFile.close();
    return 0;
}
