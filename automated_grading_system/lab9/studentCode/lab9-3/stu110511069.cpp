#include<fstream>
#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
    string op = argv[3];
    char idx;
    string s;
    string mat[127];
    ifstream codein,fin;

    codein.open("code.txt");
    while(codein>>idx>>s){
        mat[idx]=s;
    }
    codein.close();
    fin.open(argv[1]);


    ofstream fout;
    fout.open(argv[2]);
    
    if(op=="d"){
        string s,token= "";
        while(getline(fin,s)){
            //fout<<s;
            
            for(int i =0;i<s.length();i++){
                while(s[i]!=' '){
                    token += s[i];
                    i++;
                    if(i==s.length()) break;

                }
                for(int j = 0;j<127;j++){
                    if(mat[j] == token){
                        fout<<char(j);
                        token ="";
                        break;

                    }
                }
                int spa  =0;
                while(s[i] ==' '){
                    i++;
                    if(i==s.length()) break;
                    spa++;
                }
                i--;
                cout<<spa;
                if(spa>4){
                    fout<<" ";
                }
              
            }
            fout<<endl;
     }
            


        
    }
    else{
        string s;
        char ch;
        while(getline(fin,s)){
                for(int i =0;i < s.length();i++){
                    if(s[i]==' '){
                        fout<<"       ";
             
                    }
                    else {
                        fout<<mat[s[i]]<<"   ";
                        }
                }
                fout<<endl;
        }

            
    }
    
    return 0;
}
        
