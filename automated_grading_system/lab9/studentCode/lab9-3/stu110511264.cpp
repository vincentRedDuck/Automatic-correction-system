#include<bits/stdc++.h>
using namespace std;
ofstream fout;
string l[26],n[10];
void find(string &letter){
    for(int i=0;i<26;i++){
        if(l[i]==letter){
            fout<<char(65+i);
        }
    }
    for(int i=0;i<10;i++){
        if(n[i]==letter){
            fout<<i;
        }
    }
    letter="";
}
int main(int argc,char *argv[]){
    ifstream fin0,fin;
    fin0.open("code.txt");
    fin.open(argv[1]);
    fout.open(argv[2]);
    string garbage;
    for(int i=0;i<26;i++){
        fin0>>garbage;
        fin0>>l[i];
    }
    for(int i=1;i<10;i++){
        fin0>>garbage;
        fin0>>n[i];
    }
    fin0>>garbage;
    fin0>>n[0];
    if(*argv[3]=='e'){
        string s;
        while(1){
            getline(fin,s);
            cout << s << endl;
            for(int i=0;i<s.length();i++){
                if(isalpha(s[i])){
                    fout<<l[int(s[i]-65)];
                    if(i!=s.length()-1){
                        fout<<"   ";
                    }
                }
                else if(isdigit(s[i])){
                    fout<<n[int(s[i]) - int('0')];
                    if(i!=s.length()-1){
                        fout<<"   ";
                    }
                }
                else if(s[i]==' '){
                    fout<<"    ";
                }
            }
            fout<<"\n";
            if(fin.eof()){
                break;
            }
        }
    }
    else if(*argv[3]=='d'){
        string s,letter;
        int blank=0;
        while(1){
            getline(fin,s);
            for(int i=0;i<s.length();i++){
                if(s[i]!=' '){
                    letter+=s[i];
                }
                if(i==s.length()-1){
                    find(letter);
                }
                else if(s[i]==' '){
                    blank++;
                    if(s[i+1]!=' '&&blank==3){
                        blank=0;
                        find(letter);
                    }
                    if(blank==7){
                        find(letter);
                        fout<<" ";
                        blank=0;
                        
                    }
                }
            }
            fout<<"\n";
            if(fin.eof()){
                break;
            }
        }
    }
    return 0;
}
