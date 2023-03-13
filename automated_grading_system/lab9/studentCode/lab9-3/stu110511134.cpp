#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
struct MORSE{
	char ch;
	string cd;
};
MORSE mtb[36];//26+10
void codecWrt(ifstream &,ofstream &, int);

int main (int argc, char **argv){
	ifstream fcd("code.txt");
	for(int i=0;i<36;i++){
		fcd >>mtb[i].ch >>mtb[i].cd;
	}
	fcd.close();
	
	ifstream fi(argv[1]);
	ofstream fo(argv[2]);
	codecWrt(fi, fo, ((argv[3][0] == 'e')?1:2));
	
	return 0;	
}

string getCode(char ch){
	if(ch == '\n') return string("\n");
	if(ch == ' ')  return string("       ");	
	for(int i=0;i<36;i++){       /*******/
		if(ch==mtb[i].ch){
			return string(mtb[i].cd);
		}
	}
	return string("");
}

char getChar(string &wd){
	for(int i=0;i<36;i++)
		if(wd==mtb[i].cd){
			wd.clear();
			return mtb[i].ch;
		}
	return char('\0');	
}

void codecWrt(ifstream &fin,ofstream &fout, int opt){
	char ch;
    
	if(opt==1){
	 	while(fin.get(ch)){                                           /***/
            fout << getCode(ch) <<((isalnum(ch)&&isalnum(fin.peek()))?"   ":"");//
		}//3個空格
	}
	else{
	 	string wd;
	 	int num = 0;
        while(fin.get(ch)){
	 		if(ch=='.'||ch=='-'){
				wd+=ch;
				num = 0;	
			}
	 		else if(ch=='\n'){
                char yy =getChar(wd);
                if(yy=='\0')fout<<""<<endl;
                else fout<<yy<<endl;
                
                //fout <<(getChar(wd)=='\0')?"":getChar(wd)<<endl;//<<endl;	
			}
			else{//ch is a space
				num++;
                if(num==3){
                    char xx =getChar(wd);
                    if(xx=='\0')fout<<"";
                    else fout<<xx;
                    
                }
                else{
                    if(num==7){
                        fout<<" ";
                    }
                    else{
                        fout<<"";
                    }
                }
				//fout <<((num==3)?getChar(wd):((num==7)?" ":""));// 
			}
		}
	}
}
