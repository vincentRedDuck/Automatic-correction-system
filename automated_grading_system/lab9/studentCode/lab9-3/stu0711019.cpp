#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct Morse{ 
	char Letter;
        string cd;
};

string EC(char);
char DC(string&);
void Present(ifstream &,ofstream &,int);
Morse mor[36];

int main(int argc,char **argv){

        ifstream fin ("code.txt");
        for(int i=0;i<36;i++){
                fin >> mor[i].Letter >> mor[i].cd;
        }
        fin.close();
        ifstream Input(argv[1]);
        ofstream fout(argv[2]);
        Present(Input,fout,((argv[3][0] =='d')? 2 : 1 ));
}
string EC(char lt){
        if(lt == '\n'){ 
		return "\n"; 
	}
        else if(lt  == ' '){
                return "       "; 
	}
        else{
                for(int i=0;i<36;i++){
                        if(lt == mor[i].Letter)return mor[i].cd +' '; }
        }
        return "\0";
}
char DC(string &wd){
        for(int i=0;i<36;i++){
                if(wd == mor[i].cd){
                        wd.clear();
                        return mor[i].Letter; 
		}
        }
        return ' ' ;
}
void Present(ifstream &fin,ofstream &fout,int opt){

        char lt;
        if(opt == 1){
                while(fin.get(lt)){
                        EC(lt);
                        fout << EC(lt);
	       	}
        }else{
                string ss;
                int num = 0;
                while(fin.get(lt)){
                        if(lt =='-'||lt =='.'){
                                ss += lt;
			       	num =0;

                        }else if(lt=='\n'){
                                fout << DC(ss) <<endl;
                        }else{
                                num++;
                               if(num == 3)fout << DC(ss);
                               if(num == 7)fout << ' ';
                        }
                }
        }
}

