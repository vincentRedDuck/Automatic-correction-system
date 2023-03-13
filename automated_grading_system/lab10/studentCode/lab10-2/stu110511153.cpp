#include <bits/stdc++.h>
using namespace std;

struct POKEMON{
    string id;
    string en,tn;
};

POKEMON pdex[500], mypk[500];
int searchPKM(POKEMON[],int,string);
void insertSort(POKEMON[],int);

int main(int argc, char **argv)
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    string line,tok;
    int num = 0;
    while (getline(fin,line))
    {
        stringstream ss(line);
        ss>>pdex[num].id>>tok>>pdex[num].en>>pdex[num].tn;
        fout<<pdex[num].id<<" "<<pdex[num].en<<" "<<pdex[num++].tn<<endl;
    }
    fin.close();
    fout.close();

    fin.open(argv[3]);
    fout.open(argv[4]);
    int cnt = 0;
    while(fin>>tok)
    {
        int id = (isdigit(tok[0])? atoi(tok.c_str()): searchPKM(pdex, num, tok));
        if(searchPKM(mypk, cnt, pdex[id-1].en)==-1)
        {
            mypk[cnt].id = pdex[id-1].id; 
            mypk[cnt].en = pdex[id-1].en;
            cnt++;
        }
    }
    insertSort(mypk, cnt);
    for(int i=0;i<cnt; i++)
        fout<<stoi(mypk[i].id)<<" "<<mypk[i].en<<endl;
    fin.close();
    fout.close();
    
    return 0;
}
int searchPKM(POKEMON vec[],int num, string en)
{
    for(int i=0; i<num; i++)
    {
        if(vec[i].en==en) return atoi((vec[i].id).c_str());
    }
    return -1;
}
void insertSort(POKEMON vec[],int len)
{
    for(int j=1; j<len; j++)
    {
        POKEMON key(vec[j]);
        int i = j-1;
        while((i>=0) && (vec[i].id>key.id))
        {
            vec[i+1] = vec[i];
            i--;
        }vec[i+1] = key;
    }

}
