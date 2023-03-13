#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>

using namespace std;

char decode(string);
string encode(char);

int main(int argc,char *argv[]){
    string in,out,cs;
    in= argv[1];out=argv[2];

    ifstream infile;
    ofstream outfile;
    infile.open(in.c_str());
    outfile.open(out.c_str(),ios::out);
    
        cs=argv[3];
            int scnt=0;
            char ch,pk;
            string ori;
            string cnvrt="";
        if(cs=="e"){
            while (!infile.eof()){
                infile.get(ch);
                pk=infile.peek();
                if (isalnum(ch)){
                    cnvrt=encode(ch);
                    outfile<<cnvrt;
                    if (pk==' ')
                        outfile<<"       ";
                    else if(isalnum(pk))
                        outfile<<"   "; 
                }
                else if(ch=='\n')
                    outfile<<endl;
            }
        }
        if(cs=="d"){
//                infile.get(ch);
//                pk=infile.peek();
            while (!infile.eof()){
                infile.get(ch);
                pk=infile.peek();
                if (infile.eof())
                    int i=1;
                else if(ch=='\n'){
                    cnvrt=decode(ori);
                    ori="";
                    outfile<<cnvrt<<endl; 
                }    
                else if(ch=='.'||ch=='-'){
                    ori=ori+ch;
                    if(pk==' '){
                        cnvrt=decode(ori);
                        ori="";
                        outfile<<cnvrt;
                    }
                }
                else if(ch==' '){
                    scnt+=1;
                    if(pk!=' '){
                        if(scnt==3)
                                scnt=0;
                        else if (scnt>3){
                                outfile<<" ";
                                scnt=0;
                        }
                    }
                }
//                infile.get(ch);
//                pk=infile.peek(); 
            }
//            cout<<ch<<endl;
//            infile.get(ch);}
        }
/*    string a;
    cin>>a;
    cout<<decode(a)<<endl;*/
    return 0;
} 
char decode(string a){
        if(a==".-")
            return 'A';
        if(a=="-...")
            return 'B';
        if(a=="-.-.")
            return 'C';
        if(a=="-..")
            return 'D';
        if(a==".")
            return 'E';
        if(a=="..-.")
            return'F';
        if(a=="--.")
            return'G';
        if(a=="....")
            return'H';
        if(a=="..")
            return'I';
        if(a==".---")
            return'J';
        if(a=="-.-")
            return'K';
        if(a==".-..")
            return'L';
        if(a=="--")
            return'M';
        if(a=="-.")
            return'N';
        if(a=="---")
            return'O';
        if(a==".--.")
            return'P';
        if(a=="--.-")
            return'Q';
        if(a==".-.")
            return'R';
        if(a=="...")
            return'S';
        if(a=="-")
            return'T';
        if(a=="..-")
            return'U';
        if(a=="...-")
            return'V';
        if(a==".--")
            return'W';
        if(a=="-..-")
            return'X';
        if(a=="-.--")
            return'Y';
        if(a=="--..")
            return'Z';
        if(a=="-----")
            return'0';
        if(a==".----")
            return'1';
        if(a=="..---")
            return'2';
        if(a=="...--")
            return'3';
        if(a=="....-")
            return'4';
        if(a==".....")
            return'5';
        if(a=="-....")
            return'6';
        if(a=="--...")
            return'7';
        if(a=="---..")
            return'8';
        if(a=="----.")
            return'9';
        else
            return'\0';
}
string encode(char a){
    switch(a){
        case 'A':
           return ".-"; 
        case 'B':
           return "-..."; 
        case 'C':
           return "-.-."; 
        case 'D':
           return "-.."; 
        case 'E':
           return "."; 
        case 'F':
           return "..-."; 
        case 'G':
           return "--.";
        case 'H':
           return "...."; 
        case 'I':
           return ".."; 
        case 'J':
           return ".---"; 
        case 'K':
           return "-.-"; 
        case 'L':
           return ".-.."; 
        case 'M':
           return "--"; 
        case 'N':
           return "-."; 
        case 'O':
           return "---"; 
        case 'P':
           return ".--."; 
        case 'Q':
           return "--.-"; 
        case 'R':
           return ".-."; 
        case 'S':
           return "..."; 
        case 'T':
           return "-"; 
        case 'U':
           return "..-"; 
        case 'V':
           return "...-"; 
        case 'W':
           return ".--"; 
        case 'X':
           return "-..-"; 
        case 'Y':
           return "-.--"; 
        case 'Z':
           return "--.."; 
        case '0':
           return "-----"; 
        case '1':
           return ".----"; 
        case '2':
           return "..---"; 
        case '3':
           return "...--"; 
        case '4':
           return "....-"; 
        case '5':
           return "....."; 
        case '6':
           return "-...."; 
        case '7':
           return "--..."; 
        case '8':
           return "---.."; 
        case '9':
           return "----.";
        default:
            return "";
    }
}

