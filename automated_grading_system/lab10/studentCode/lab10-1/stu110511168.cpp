#include<bits/stdc++.h>
using namespace std;

ifstream fin;
ofstream fout;

int running(){
    string s;
    fin >> s;
    if(fin.eof())
        return 1;

    fout << "=====\nDomain name: ";
    int flag = 0, at = 0;
    string method;
    for(int i=0; i<s.size(); ++i){
        if(flag == 0 && s[i] == ':'){
            i += 2;
            flag = 1;
        }
        
        else if(flag == 1 && s[i] == '/')
            flag = 2;

        else if(flag == 1)
            fout << s[i];
        
        else if(flag == 2 && s[i] == '?'){
            at = i;
            fout << "\nMethod: " << method;
            flag = 0;
            break;
        }

        else if(flag == 2 && s[i] == '/')
            method = "";
             
        else if(flag == 2)
            method += s[i];
    }
    
    string a;
    for(int i=at+1; i<s.size(); ++i){
        if(s[i] == '=' && i == s.size()-1)
            break;
             
        else if(s[i] == '=' && s[i+1] == '&')
            a = "";
        
        else if(s[i] == '=' && i != s.size()-1){
            fout << "\n" << a << ": ";
            a = "";
            flag = 1;
        }
        
        else if(s[i] == '&')
            flag = 0;

        else if(flag == 1)
            fout << s[i];

        else
            a += s[i];
    }

    fout << "\n";

    return 0;
}

int main(int argc, char **argv){
    fin.open(argv[1]);
    fout.open(argv[2]);

    while(1)
        if(running())
            break;

    fout << "=====\n";
    return 0;
}

