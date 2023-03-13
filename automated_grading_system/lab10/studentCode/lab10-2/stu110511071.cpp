#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct pkdir{
    string num;
    string eng;
    string tw;
};
struct bag{
    int nu;
    string name;
};
const int MAX=500;

int idtr(pkdir[],string);
bool check(int,bag[]);
void sort(int,bag[]);
int main (int argc,char *argv[]){
    ifstream dex,bg;
    ofstream sdex,sbg;
    string in1,ot1,in2,ot2;
    in1=argv[1];
    in2=argv[3];
    ot1=argv[2];
    ot2=argv[4];
    dex.open(in1.c_str());
    bg.open(in2.c_str());
    sdex.open(ot1.c_str(),ios::out);
    sbg.open(ot2.c_str(),ios::out);
    
    pkdir dx[MAX];
    string main,tk;
    stringstream ss;
    int cnt =0;
        getline(dex,main);
        ss.str(main);
    while(!dex.eof()){
        ss>>tk;
        dx[cnt].num=tk;
        sdex<<tk<<" ";
        ss>>main>>tk;
        dx[cnt].eng=tk;
        sdex<<tk<<" ";
        ss>>tk;
        dx[cnt].tw=tk;
        if(!dex.eof())
        sdex<<tk<<endl;
        cnt++; 
        getline(dex,main);
        ss.str(main);
    }
    int bnt=0;
    bag mbg[MAX];
    for(int i=0;i<MAX;i++){
        mbg[i].nu=0;
        mbg[i].name="";
    }
    
    while(bg>>tk){
        int id=idtr(dx,tk);
        if (check(id,mbg)&&id>0){
            mbg[bnt].nu=id;
            mbg[bnt].name=dx[id-1].eng;
            bnt++;
//            cout<<mbg[bnt].name<<endl;
        }
    }
    sort(bnt,mbg);
    for(int i=0;i<bnt;i++){
        sbg<<mbg[i].nu<<" "<<mbg[i].name<<endl;
//        cout<<mbg[i].nu<<" "<<mbg[i].name<<endl;
    }
    dex.close();
    sdex.close();
    bg.close();
    sbg.close();
    return 0;
}
int idtr(pkdir dx[],string a){
    int n=atoi(a.c_str());
    for (int i=0;i<MAX;i++){
        if (a==dx[i].eng)
            return atoi((dx[i].num).c_str());
    }
    return n;
}
bool check(int a,bag bg[]){
    bool out=true;
        for(int i=0;i<MAX;i++)
            if(bg[i].nu==a)
                out=false;
    return out;
}
void sort(int cnt,bag bg[]){
    for(int i=1;i<cnt;i++){
        bag th=bg[i];
        for(int j=i;j>0;j--){
            if(bg[j-1].nu>th.nu){
                bg[j]=bg[j-1];
                bg[j-1]=th;
            }
            else
                continue;
        }
    }
}
