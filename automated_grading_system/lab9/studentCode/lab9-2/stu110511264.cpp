#include<bits/stdc++.h>
using namespace std;
struct group{
    string name;
    int grade[3]={0};
    double avg=0;
};
bool namecmp(string a,string b){
    if(a[0]>b[0]){
        return 1;
    }
    else if(a[0]==b[0]){
        for(int i=1; i<=max(a.size(), b.size()); i++){
            if(a[i]>b[i]){
                return 1;
            }
            else if(a[i]<b[i]){
                return 0;
            }
        }
    }

    return 0;
}
void f1(group g[],int length){
    group tmp;
    for(int i=length-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(g[j].avg>g[j+1].avg){
                tmp=g[j];
                g[j]=g[j+1];
                g[j+1]=tmp;
            }
        }
    }
}
void f2(group g[],int length){
    group tmp;
    bool b;
    for(int i=length-1;i>0;i--){
        for(int j=0;j<i;j++){
            b=namecmp(g[j].name,g[j+1].name);
            if(b){
                tmp=g[j];
                g[j]=g[j+1];
                g[j+1]=tmp;
            }
        }
    }
}
int main(int argc, char *argv[]){
    string file_name;
    ifstream fin;
    fin.open(argv[2]);
   if(argc==3){
        file_name=argv[2];
        file_name+=".out";
    }
    else if(argc==4){
        file_name=argv[3];
    }
    ofstream fout;
    fout.open(file_name);
    int length;
    fin>>length;
    group g[length];
    for(int i=0;i<length;i++){
        fin>>g[i].name;
        for(int j=0;j<3;j++){
            fin>>g[i].grade[j];
        }
    }
    for(int i=0;i<length;i++){
        for(int j=0;j<3;j++){
            g[i].avg+=g[i].grade[j];
        }
        g[i].avg/=3;
    }
    if(*argv[1]=='1'){
        f1(g,length);
        for(int i=0;i<length;i++){
            fout<<g[i].name<<" ";
            for(int j=0;j<3;j++){
                fout<<g[i].grade[j]<<" ";
            }
        fout<<fixed<<setprecision(4)<<g[i].avg<<"\n";
        }
    }
    else if(*argv[1]=='2'){
        f2(g,length);
        for(int i=0;i<length;i++){
            fout<<g[i].name<<" ";
            for(int j=0;j<3;j++){
                fout<<g[i].grade[j]<<" ";
            }
        fout<<fixed<<setprecision(4)<<g[i].avg<<"\n";
        }
    }
    
    return 0;
}
