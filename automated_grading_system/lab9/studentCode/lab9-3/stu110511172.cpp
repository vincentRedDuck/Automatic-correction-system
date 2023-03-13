#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

string encode(char n){
    string fin;
    if(n=='A'||n=='E'||n=='F'||n=='H'||n=='I'||n=='J'||n=='L'||n=='P'||n=='R'||n=='S'||n=='U'||n=='V'||n=='W'||n=='1'||n=='2'||n=='3'||n=='4'||n=='5')
        fin += ".";
    if(n=='B'||n=='C'||n=='D'||n=='G'||n=='K'||n=='M'||n=='N'||n=='O'||n=='Q'||n=='T'||n=='X'||n=='Y'||n=='Z'||n=='6'||n=='7'||n=='8'||n=='9'||n=='0')
        fin += "-";
    if(n=='B'||n=='C'||n=='D'||n=='F'||n=='H'||n=='I'||n=='K'||n=='N'||n=='S'||n=='U'||n=='V'||n=='X'||n=='Y'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6')
        fin += ".";
    if(n=='A'||n=='G'||n=='J'||n=='L'||n=='M'||n=='O'||n=='P'||n=='Q'||n=='R'||n=='W'||n=='Z'||n=='1'||n=='7'||n=='8'||n=='9'||n=='0')
        fin += "-";
    if(n=='B'||n=='D'||n=='G'||n=='H'||n=='L'||n=='Q'||n=='R'||n=='S'||n=='V'||n=='X'||n=='Z'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7')
        fin += ".";
    if(n=='C'||n=='F'||n=='J'||n=='K'||n=='O'||n=='P'||n=='U'||n=='W'||n=='Y'||n=='1'||n=='2'||n=='8'||n=='9'||n=='0')
        fin += "-";
    if(n=='B'||n=='C'||n=='F'||n=='G'||n=='H'||n=='L'||n=='P'||n=='Z'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8')
        fin += ".";
    if(n=='J'||n=='Q'||n=='V'||n=='X'||n=='Y'||n=='1'||n=='2'||n=='3'||n=='9'||n=='0')
        fin += "-";
    if(n=='9'||n=='5'||n=='6'||n=='7'||n=='8')
        fin += ".";
    if(n=='1'||n=='2'||n=='3'||n=='4'||n=='0')
        fin += "-";
    return fin;
}

char decode(string n){
    int len = n.length();
    char f = '*';
    if(len==1){
        f = (n[0]=='.'?'E':'T');}
    else if(len==2){
        f = (n[0]=='.'?(n[1]=='.'?'I':'A'):(n[1]=='.'?'N':'M'));}
    else if(len==3){
        f =  (n[0]=='.'?(n[1]=='.'?(n[2]=='.'?'S':'U'):(n[2]=='.'?'R':'W')):(n[1]=='.'?(n[2]=='.'?'D':'K'):(n[2]=='.'?'G':'O')));}
    else if(len==4){
        f =  (n[0]=='.'?(n[1]=='.'?(n[2]=='.'?(n[3]=='.'?'H':'V'):'F'):(n[2]=='.'?'L':(n[3]=='.'?'P':'J'))):(n[1]=='.'?(n[2]=='.'?(n[3]=='.'?'B':'X'):(n[3]=='.'?'C':'Y')):(n[3]=='.'?'Z':'Q')));}
    else if(len==5){
        f =  (n[0]=='.'?(n[1]=='.'?(n[2]=='.'?(n[3]=='.'?(n[4]=='.'?'5':'4'):'3'):'2'):'1'):(n[1]=='.'?'6':(n[2]=='.'?'7':(n[3]=='.'?'8':(n[4]=='.'?'9':'0')))));}
    return f;
}

int main(int argc,char *argv[]){
    
    ifstream fin;
    ofstream fout;

    fin.open(argv[1]);
    fout.open(argv[2]);
    
    string line;

    if (!(strcmp(argv[3],"e"))){
        getline(fin,line);
        while(!fin.eof()){
            int len = line.length();
            string word;
            for(int i=0;i<len;i++){
                if(isalpha(line[i])||isdigit(line[i])){
                    word = word + encode(line[i])+"   ";
                }
                if(i==(len-1)){
                    fout << word;
                    word = "";
                }
                if(line[i] == ' '){
                    fout << word << "    ";
                    word = "";
                }
            }
        fout << endl;
        getline(fin,line);
        }
    }
    if(!(strcmp(argv[3],"d"))){
        getline(fin,line);
        while(!fin.eof()){
            int len = line.length();
            int t = 0;
            string word;
            for(int i=0;i<len;i++){
                if(line[i]!=' '){
                    word = word + line[i];
                }
                if(line[i] == ' '){
                    t++;
                }
                if(i==(len-1)){
                    fout << decode(word);
                    word = "";
                }                    
                if(t==3&&line[i+1]!=' '){
                    fout << decode(word);
                    t++;
                    t=0;
                    word = "";
                }
                if(t==7){
                    fout << decode(word) << " ";
                    word = "";
                    t=0;
                }
            }fout << endl;
            getline(fin,line);
        }
    }
return 0;
}
