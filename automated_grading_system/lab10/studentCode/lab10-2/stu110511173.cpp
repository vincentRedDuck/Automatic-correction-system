#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct POKE
{
    string ID;
    string en;
    string cn;
};



int main(int argc, char *argv[])
{
    ifstream fin1(argv[1]);
    ifstream fin2(argv[3]);
    ofstream fout1(argv[2]);
    ofstream fout2(argv[4]);
    
    POKE index[500];
    POKE mypok[1000];
    string line,token;
    int i=1;
    while(getline(fin1,line))
    {
        stringstream ss(line);
        ss >> index[i].ID >> token >> index[i].en >> index[i].cn ;
        //fout1 << index[i].ID << " " << index[i].en << " " << index[i].cn << endl;
        i++;
    }
    for(int n=1; n<i; n++)
    {
        for(int m=1; m<i; m++)
        {
            if(atoi(index[m].ID.c_str())== n)
            {
                fout1 << index[m].ID << " " << index[m].en << " " << index[m].cn << endl;
                break;
            }
        }
        //fout1 << index[i].ID << " " << index[i].en << " " << index[].cn << endl;
    }
    fin1.close();fout1.close();
    
    string tok;
    int num=0;
    while(fin2>>tok)
    {
        if(isdigit(tok[0])&&atoi(tok.c_str())!=0)
        {
            for(int j=1; j<i ; j++)
            {
                if(atoi(tok.c_str())==atoi(index[j].ID.c_str()))
                {
                    mypok[num].ID = index[j].ID;
                    mypok[num].en = index[j].en;
                }
            }
        }

        else if(isalpha(tok[0]))
        {
            for(int j=1; j<i ; j++)
            {
                if(tok==index[j].en)
                {
                    mypok[num].ID = index[j].ID ;
                    mypok[num].en = index[j].en ;
                }
            } 
        }
        num++;
    }
    
    /*for(int j=1; j<num ;j++)
    {
        POKE key(mypok[j]);
        int p=j-1;
        while((p>=0)&&mypok[p].ID>key.ID)
        {
            mypok[p+1] = mypok[p];
            
            p--;
        }
        mypok[p+1] = key;
    }*/
    
    //POKE temp;
    for (int i=0; i< num-1; i++) {
        for (int j=0; j<num-i-1; j++) {
            if (mypok[j].ID > mypok[j+1].ID) {
                POKE temp = mypok[j];
                mypok[j] = mypok[j+1];
                mypok[j+1] = temp;
            }
        }
    }

    for(int i=0; i<num; i++)
    {
        if(mypok[i].ID != mypok[i+1].ID)
            fout2 << atoi(mypok[i].ID.c_str()) << " " << mypok[i].en << endl;
    }
    fin2.close();fout2.close();
    return 0;
}
