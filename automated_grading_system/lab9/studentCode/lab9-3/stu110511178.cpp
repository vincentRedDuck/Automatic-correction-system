#include<bits/stdc++.h>

using namespace std;
struct cod{
    char in;
    string line;
};
int main(int k,char *arg[]){

ifstream F1("code.txt");
ifstream F2(arg[1]);
ofstream o1(arg[2]);

string sen,str,sp;
char ch;
int count=0;

cod code[36];

    while(!F1.eof()){ 
        for(int i=0;i<36;i++){
            F1.get(code[i].in);
            getline(F1,sp,' ');           
            getline(F1,code[i].line);
         }
        code[0].in='A';
    }
//    cout<<code[0].in<<code[0].line;
    if(strcmp(arg[3],"e")==0){
        while(!F2.eof()){
            getline(F2,sen);
                for(int k=0;k<sen.length();k++){
                    if(sen.at(k)==' ')o1<<"    ";
                else{
                    for(int i=0;i<36;i++){
                        if(code[i].in==sen.at(k))o1<<code[i].line;
                    }
                }
                    o1<<"   ";
                }
                o1<<"\n";    
                    
        }

    }
    else {
        
        
        sen.clear();
        while(!F2.eof()){
            getline(F2,str);
            str+=" ";
            for(int m=0;m<str.length();m++){
                
            if(str.at(m)==' ' ){
                if(count==0){
                    for(int i=0;i<36;i++){
                        if(sen==code[i].line){
                            o1<<code[i].in;
                        }
                    }
                }                
                count++;
                sen.clear();
                if(count==7){
                    o1<<" ";
                    count=0;
                }
            }
            else {
                sen+=str.at(m);
                count=0;
            }
            
           }
        o1<<"\n"; 
       }
    
    }

return 0;
}     
            








