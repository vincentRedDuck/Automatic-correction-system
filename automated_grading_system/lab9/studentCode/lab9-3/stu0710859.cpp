#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct morse{
    char alp;
    string code;
};

int main(int argc, char *argv[]){
    ifstream file1;
    ofstream file2;
    ifstream file3;
    string inf = argv[1], outf = argv[2], open, temp;
    char c = argv[3][0], a;
    struct morse m[36];
    int i, j, len, s=1;
    file3.open("code.txt");
    for(i = 0; i < 36; i++){
        file3 >> m[i].alp >> m[i].code;
    }
    if(c == 'e'){
        file1.open(inf);
        file2.open(outf);
        while(getline(file1,open)){
            while(s > 0){
                s = open.find(' ');
                temp = open.substr(0,s);
                open.erase(0,s+1);
                for(i = 0; i < temp.length(); i++){
                    for(j = 0; j < 36; j++){
                        if(temp[i] == m[j].alp){
                            file2 << m[j].code;
                            if(i == temp.length()-1){
                                file2 << "       ";
                            } 
                            else{
                                file2 << "   ";
                            }
                            break;
                        }
                    }
                }
            }
            s = 1;
            file2 << endl;
        }
    }
    else if( c == 'd'){
        file1.open(inf);
        file2.open(outf);
        while(getline(file1,open)){
            while(open.length() != 0){
                s = open.find(' ');
                temp = open.substr(0,s);
                open.erase(0,s);
                for(i = 0; i < 36; i++){
                    if(temp == m[i].code){
                        file2 << m[i].alp;
                        //cout << s << " " << temp << " " << m[i].alp << endl;
                    }
                }
                if(open[3] == ' '){
                    file2 << " ";
                    open.erase(0,7);
                }
                else{
                    open.erase(0,3);
                }
            }
            file2 << endl;
        }        
    }
    file1.close();
    file2.close();
    return 0;
}
