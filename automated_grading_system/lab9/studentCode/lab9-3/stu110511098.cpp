#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct morse{
    char al;
    string code;
};
morse list[36];

int main(int argc,char *argv[]){
    ifstream codetable("code.txt");
    for(int i=0;i<36;i++){
        codetable >> list[i].al >> list[i].code;
    }
    codetable.close();

    ifstream in_file(argv[1]);
    ofstream out_file(argv[2]);

    char a;
    if(argv[3][0] == 'e'){
        while(in_file.get(a)){
            if(a == '\n')
                out_file<<"\n";
            if(a == ' ')
                out_file<<"       ";
            for(int i=0;i<36;i++){
                if(a == list[i].al){
                    out_file<<list[i].code;
                }
            }
            if(isalnum(a)&&isalnum(in_file.peek()))
                out_file << "   ";
        }
    }
    if(argv[3][0] == 'd'){
        int space=0;
        string w;
        while(in_file.get(a)){
            if(a == ' '){
                space++;
                if (space == 7)
                    out_file<<' ';   
            }
            if(a == '.'||a == '-'){
                w += a;
                space = 0; 
            }
            for(int i=0;i<36;i++){
                if(w == list[i].code && ( in_file.peek() == ' ' || in_file.peek() == '\n')){
                    out_file<<list[i].al;
                    w.erase();
                    if(in_file.peek() == '\n')
                        out_file<< "\n";
                }
            }       
        }
    }
    return 0;
}

