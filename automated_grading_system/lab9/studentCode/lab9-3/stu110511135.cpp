#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
void encoder(char[], string v[], char[], ofstream&);
void decoder(ifstream&, ofstream&, string[], char[]);
int main(int argc, char *argv[]){
    char m[36]; 
    string v[36];
    for(int i=0; i<26; i++){
        m[i] = char(i+65);
    }
    for(int i=26; i<35; i++){
        m[i] = char(i-25+48);
    }
    v[0] = ".-"; v[1] = "-..."; v[2] = "-.-."; v[3] = "-..";
    v[4] = "."; v[5] = "..-."; v[6] = "--."; v[7] = "....";
    v[8] = ".."; v[9] = ".---"; v[10] = "-.-"; v[11] = ".-..";
    v[12] = "--"; v[13] = "-."; v[14] = "---"; v[15] = ".--.";
    v[16] = "--.-"; v[17] = ".-."; v[18] = "..."; v[19] = "-";
    v[20] = "..-";v[21] = "...-"; v[22] = ".--"; v[23] = "-..-";
    v[24] = "-.--"; v[25] = "--.."; 
    v[26] = ".----"; v[27] = "..---"; v[28] = "...--";
    v[29] = "....-"; v[30] = "....."; v[31] = "-....";
    v[32] = "--..."; v[33] = "---.."; v[34] = "----.";
    v[35] = "-----"; m[35] = '0';
    
    char *outfile = argv[2];
    char *infile = argv[1];
    char *mode = argv[3];
    ifstream fin(infile);
    ofstream fout(outfile);
    char word[100];
    if(!strcmp(mode,"e")){
        fin >> word;
        while(!fin.eof()){
            encoder(word, v, m, fout);
            if(fin.peek() == '\n'){
                fout << "\n";
            }else{
                fout << "       ";
            }
            fin >> word;
        }
    }else{
        decoder(fin, fout, v, m);

    }
return 0;
}

void encoder(char w[], string v[], char m[], ofstream& fout){
    for(int i=0; i<strlen(w); i++){
        for(int j=0; j<36; j++){
            if(w[i]==m[j]){
                fout << v[j] << "   ";
            }
        }
    }
}
void decoder(ifstream& fin, ofstream& fout, string v[], char m[]){
    char ch;
    int count=0;
    char word[10];
    char word2[300];
    while(fin >> word){
        count=0;
        for(int i=0; i<36; i++){
            if(!strcmp(word,v[i].c_str())){
                fout << m[i];
            }
        }
        /*if(fin.peek()!='\n'){
            fin.getline(word2,3);
            if(fin.peek()==' '){
                fout << " ";
            }
        }else {
            fout << "\n";
        }*/
        while(fin.get(ch)){
            if(ch==' '){
                count++;
            }
            if(ch != ' '){
                fin.putback(ch);
                break;
            }
        }
        if(count>4){
            fout << ' ';
        }else if(ch == '\n'){
            fout << '\n';
        }
        
    }
}
