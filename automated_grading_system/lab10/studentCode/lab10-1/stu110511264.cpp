#include<bits/stdc++.h>
using namespace std;
struct ob{
    string type = "";
    string content = "";
};
int main(int argc ,char *argv[]){
    ifstream fin;
    ofstream fout;
    fout.open(argv[2]);
    fin.open(argv[1]);
    fout<<"=====\n";
    string url;
while(fin >> url){
    //string url;
    ob x[20];
    int n=1;
    //getline(fin,url);
    int at1 = 0,at2,at3,at4,equ_at,and_at=url.length()-1;
    int slash=0;
    for(int i=0;i<url.length();i++){
        if(url[i]==':' && at1 == 0){
            at1=i+3; 
        }
        if(url[i]=='/'){
            slash++;
            if(slash==3){
                at2=i;
            }
        }
    }
    fout<<"Domain name: "<<url.substr(at1,at2-at1)<<"\n";
    for(int i=0;i<url.length();i++){
        if(url[i]=='?'){
            at3=i;
            //cout << at3 << endl;
            for(int j=at3;j>0;j--){
                if(url[j]=='/'){
                    at4=j+1;
                    //cout << at4 << endl;
                    break;
                }
            }
        }
    }
    if(at3 != at4) {
        fout<<"Method: "<<url.substr(at4,at3-at4)<<"\n";
    }
    else {
        fout << "Method: \n";
    }
    for(int i=at3;i<url.length();i++){
        if(url[i]=='='){
            equ_at=i;
            x[0].type=url.substr(at3+1,i-at3-1);
            break;
        }
    }
    for(int i=at3;i<url.length();i++){
        if(url[i]=='&'){
            and_at=i;
            x[0].content=url.substr(equ_at+1,i-equ_at-1);
            break;
        }
        if(i==url.length()-1){
            x[0].content=url.substr(equ_at+1,i-equ_at);
        }
    }
    for(int i=and_at+1;i<url.length();i++){
        if(url[i]=='='){
            equ_at=i;
            x[n].type=url.substr(and_at+1,i-and_at-1);
        }
        if(i==url.length()-1&&url[i]!='='){
            x[n].content=url.substr(equ_at+1,i-equ_at);
            cout << x[n].content << endl;
        }
        
        if(url[i]=='&'){
            and_at=i;
            x[n].content=url.substr(equ_at+1,i-equ_at-1);
            cout << x[n].content << endl;
            n++;
        }
    }
    for(int i=0;i<20;i++){
        if(x[i].content!=""){
            fout<<x[i].type<<": "<<x[i].content<<"\n";
        }
    }
    fout<<"=====\n";
}
    return 0;
}
