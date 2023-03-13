#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

struct pokemon
{
    string eng;
    string chin;
    int number;
    bool used;
};

void new_Pokedex(istringstream &iss,ofstream &out_file,pokemon p[],int i)
{
    string a,b,c,d;
    
    iss>>a>>b>>c>>d;

    /*string str=iss.str();
    int i=0;
    while(str[i]==' ')
    {
        i++;
    }
    iss.seekg(i-1);
    iss.getline(iss,b,' ');

    str=iss.str();
    i=0;
    while(str[i]==' ')
    {
        i++;
    }
    iss.seekg(i-1);
    iss.getline(iss,c,' ');

    str=iss.str();
    i=0;
    while(str[i]==' ')
    {
        i++;
    }
    iss.seekg(i-1);
    iss.getline(iss,d,' ');*/
    int digit=atoi(a.c_str());
    
    pokemon pk={c,d,digit,false};
    p[i]=pk;
    
    out_file<<a<<" "<<c<<" "<<d<<endl;

}

int main(int argc,char *argv[])
{
    ifstream old_poke(argv[1]);
    ofstream new_poke(argv[2]);
    ifstream unsorted(argv[3]);
    ofstream sorted(argv[4]);

    string input;
    pokemon p[493];
    int num=0;
    while(getline(old_poke,input))
    {
        istringstream iss;
        iss.str(input);
        new_Pokedex(iss,new_poke,p,num);
        num++;
        /*ostringstream str;
        if(str.str().length()>0)
        {
            new_poke<<endl;
        }*/
    }
     
    /*for(int i=0;i<493;i++)
    {
        cout<<p[i].eng<<" "<<p[i].chin<<" "<<p[i].number<<" "<<p[i].used<<endl;
    }*/

    string line;
    while(unsorted>>line)
    {
        if(isdigit(line[0]))
        {
            int n=atoi(line.c_str());
            for(int i=0;i<493;i++)
            {
                if(p[i].number==n)
                {
                    p[i].used=true;
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<493;i++)
            {
                if(p[i].eng==line)
                {
                    p[i].used=true;
                    break;
                }
            }
        }
    }

    for(int i=0;i<493;i++)
    {
        if(p[i].used==true)
        {
            sorted<<p[i].number<<" "<<p[i].eng<<endl;
        }
    }

    new_poke.close();
    old_poke.close();
    unsorted.close();
    sorted.close();
    return 0;
}
