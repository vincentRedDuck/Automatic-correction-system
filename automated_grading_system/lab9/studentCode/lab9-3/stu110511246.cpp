#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct morse{
    string a;
    string b;
};
morse moscode[36];
int main(int argc,char *argv[]){
    ifstream fin;
    int i=0;
    fin.open("code.txt");
    string line;
    while(getline(fin,line)){
        stringstream ss(line);
        ss>>moscode[i].a>>moscode[i].b;
        i++;
    }
    fin.close();
    if(argv[3][0]=='e'){
        ifstream fin1;
        fin1.open(argv[1]);
        string l;
        ofstream fout1;
        fout1.open(argv[2]);
        while(getline(fin1,l)){
            for(int i=0;i<l.length();i++){
                if(l[i]==' '){
                    fout1<<"       ";
                }
                else{
                    string tmp;
                    tmp.append(1,l[i]);//將新的詞往後加
                    for(int j=0;j<36;j++){
                        if(moscode[j].a==tmp){
                            fout1<<moscode[j].b<<" ";

                        }
                    }
                }
            }
            fout1<<endl;
        }
        fin1.close();
        fout1<<endl;
        fout1.close();
    }
    else{
        ifstream fin2;
        fin2.open(argv[1]);
        string l2;
        ofstream fout2(argv[2]);
        while(getline(fin2,l2)){
            stringstream ss(l2);
            string tok;
            int count=0;
            while(getline(ss,tok,' ')){
                if(tok==""){
                    count++;
                    if(count==6){
                        fout2<<" ";
                        count=0;
                    }
                }
                else{
                    count=0;
                    for(int i=0;i<36;i++){
                        if(moscode[i].b==tok){
                            fout2<<moscode[i].a;
                        }
                    }
                }
            }
            fout2<<endl;
        }
        fout2.close();
    }
    return 0;
}

