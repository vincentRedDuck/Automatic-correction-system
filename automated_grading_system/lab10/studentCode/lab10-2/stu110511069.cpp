#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(int argc,char **argv){
    string index[500];
    bool shout[500]={false};
    string line;
    int imax = 0;
    char c;
    ifstream dexin(argv[1]),fin(argv[3]);
    ofstream fout(argv[4]),dexout(argv[2]);
    while(getline(dexin,line)){
        stringstream ss(line);
        int i;
        string temp,name;
        ss>>temp;
        i = atoi(temp.c_str());
        imax = i+1;
        dexout<<temp<<" ";
        ss>>temp;
        ss>>name;
        ss>>temp;
        dexout<<name<<" ";
        dexout<<temp<<endl;
        index[i]= name;
    }
    while(getline(fin,line)){
        cout<<line;
        stringstream ss(line);
        string pok;
        while(ss>>pok){
            if(pok.length()>0&&pok[0]>='0'&&pok[0]<='9'){
                int n = atoi(pok.c_str());
                if(n>0&&n<imax){
                    shout[n] = true;
                }
            }
            
            else{
                for(int i =0;i<imax;i++){
                    if(index[i] == pok){
                        shout[i] = true;
                        break;
                    }
                }
            }

        }
    }
    for(int i =0;i<imax;i++){
        if(shout[i]){
            fout<<i<<" "<<index[i]<<endl;
        }
    }
    return 0;
}
