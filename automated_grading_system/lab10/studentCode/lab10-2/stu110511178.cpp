#include<bits/stdc++.h>

using namespace std;

struct pokemon{
    string nu;
    string en;
    string cn;
    bool appear=0;
};

int main(int k,char **argv){

ifstream F1(argv[1]);


struct pokemon poke[493];
string list,re;
char ch;    
int x=0;
     while  (getline(F1,list)){
        istringstream ss(list);
        
         ss>>poke[x].nu;
         ss>>re;
        ss>>poke[x].en;
        ss>>poke[x].cn;
        x++;
    }
F1.close();
//cout<<poke[1].nu;

ofstream n1(argv[2]);

    for(int i=0;i<493;i++){

        n1<<poke[i].nu<<" "<<poke[i].en<<" "<<poke[i].cn<<endl;
    }
n1.close();

ofstream o1(argv[4]);
ifstream my(argv[3]);
string name;
    while(my>>name){
        for(int i=0;i<493;i++){
            int j=atoi(name.c_str());
            int y=atoi(poke[i].nu.c_str());            
            if(j==y || strcmp(name.c_str(),poke[i].cn.c_str())==0 || strcmp(name.c_str(),poke[i].en.c_str())==0){
                poke[i].appear=1;
            }
//            cout<<poke[i].appear;
        }
    name.clear();
    }

for(int i=0;i<493;i++){
    int a=atoi(poke[i].nu.c_str());
    if(poke[i].appear==1){
        o1<<a<<" "<<poke[i].en<<endl;
    }
}


    

        
        


return 0;
}
