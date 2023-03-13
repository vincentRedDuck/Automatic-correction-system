#include<bits/stdc++.h>
using namespace std;

ifstream fin;
ofstream fout;

string code[36];

void en(string s){
    for(int i=0; i<s.size(); ++i){
        if(s[i] == ' ')
            fout << "       ";

        else if(s[i] == '\n')
            fout << "\n";
        
        else{
            if(isdigit(s[i]) && s[i]!= '0')
                fout << code[int(s[i])-int('0') + 25];
            
            else if(s[i] == '0')
                fout << code[35];

            else
                fout << code[int(s[i])-int('A')];

            if(i!=s.size())
                if(s[i+1] != ' ' && s[i+1] != '\n')
                    fout << "   ";
        }
    }
}

char find(string s){
    for(int i=0; i<36; ++i)
        if(s == code[i]){
            if(i < 26)
                return char(i+(int)'A');

            else if(i < 35)
                return char(i-25+(int)'0');

            else
                return '0';
        }

    return '0';
}

void de(string s){
    string out;
    for(int i=0, blank=0; i<s.size(); ++i){
        if(s[i] == ' '){
            if(blank == 0)
                fout << find(out);

            out = "";
            ++blank;
        }
        
        else if(s[i] == '\n' && out != ""){
            fout << find(out) << "\n";
            out = "";
        }

        else{
            if(blank == 7)
                fout << " ";

            blank = 0;
            out += s[i];
        }
    }
}


int main(int argc, char *argv[]){
    fin.open("code.txt");
    for(int i=0; i<36; ++i){
        char ch;
        fin >> ch >> code[i];
    }

    fin.close();

    fin.open(argv[1]);
    fout.open(argv[2]);
    
    string w;
    while(1){
        string s;
        getline(fin, s);
        if(fin.eof())
            break;
        
        w = w + s + '\n';
    }
        
    if(*argv[3] == 'd')
        de(w);

    else
        en(w);

    return 0;
}

