#include<bits/stdc++.h>

using namespace std;

string en[493],ch[493];
vector <int> monster (493, 0); //int monster={0}
ifstream fin;
ofstream fout;
bool ensaved=0;

void givename(){
    string word;
    int n=0;
    for(int i = 0; i < 2466; ++i){
        fin>>word;
        if(ensaved==true){
            ch[n]=word;
            ensaved=false;
            //cout << ch[n] << endl;
            ++n;
        }
        else if(isalpha(word[0])&&ensaved==false){
            en[n]=word;
            ensaved=true;
        }
    }
}
void foutname(){
    for(int i=0;i<493;i++){
        if(i+1<10){
            fout<<"00"<<i+1<<" "<<en[i]<<" "<<ch[i]<<"\n";
        }
        else if(i+1<100){
            fout<<"0"<<i+1<<" "<<en[i]<<" "<<ch[i]<<"\n";
        }
        else{
            fout<<i+1<<" "<<en[i]<<" "<<ch[i]<<"\n";
        }
    }
}

int main(int argc, char *argv[]){
    string garbage;
    fin.open(argv[1]);
    fout.open(argv[2]);
    givename();
    foutname();
    fin.close();
    fout.close();
    fin.open(argv[3]);
    fout.open(argv[4]);
    string s;
    while(fin>>s){
        if(isdigit(s[0])){
            monster[stoi(s)-1]++;
        }
        else{
            for(int i=0;i<493;i++){
                if(en[i]==s){
                    monster[i]++;
                }
            }
        }
    }
    for(int i=0;i<493;i++){
        if(monster[i]!=0){
            fout<<i+1<<" "<<en[i]<<"\n";
        }
    }
    return 0;
}
