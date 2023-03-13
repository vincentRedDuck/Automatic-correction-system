#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct morse{
    string ch;
    string str;
};
char c;
string temp, temp2;
morse m[36];
/*void encode(char argv[1], char argv[2]){
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in_file" << endl;
    ofstream out_file;
    out_file.open(argv[2], ios::trunc);
    if(out_file.fail())cout << "ERROR out_file" << endl;
    while(in_file.get(c)){
        if(int(c)-65>=0)out_file << m[int(c)-65].str;
        else if(int(c)-49>=0)out_file << m[int(c)-49+26].str;
        else if(int(c)==48)out_file << m[35].str;
        else out_file << c;
        if(in_file.peek(c)!='\0')out_file << "   ";
    }
    in_file.close();
    out_file.close();
    return;
}
void decode(char argv[1], char argv[2]){
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in_file" << endl;
    ofstream out_file;
    out_file.open(argv[2], ios::trunc);
    if(out_file.fail())cout << "ERROR out_file" << endl;
    while(getline(in_file, temp2)){
        while(temp.substr(0, in_file.find(" "))){
            in_file.erase(0, in_file.find(" ")+4);
            for(int i=0; i<36; i++){
                if(temp.compare(m[i].str)==0){
                    out_file << m[i].ch;
                    break;
                }
            }
            if(temp.peek(c)!='\0')out_file << " ";
        }
        if(in_file.peek(c)!='\0')out_file << "\n";
    }
    in_file.close();
    out_file.close();
    return;
}*/
int main(int argc, char *argv[]){
    ifstream code;
    ifstream in_file;
    ofstream out_file;

    code.open("code.txt");
    //if(code.fail())cout << "ERROR code" << endl;
    for(int i=0; i<36; i++){
        getline(code, temp,' ');
        m[i].ch=temp;//
        getline(code,temp);
        m[i].str = temp;
    }
    code.close();
 if(!strcmp(argv[3],"e")){

        in_file.open(argv[1]);
        if(in_file.fail())cout << "ERROR in_file" << endl;
        //ofstream out_file;
        out_file.open(argv[2]);
        if(out_file.fail())cout << "ERROR out_file" << endl;
        while(in_file.get(c)){
            if(int(c)-65>=0)out_file << m[int(c)-65].str;
            else if(int(c)-49>=0)out_file << m[int(c)-49+26].str;
            else if(int(c)==48)out_file << m[35].str;
            //else out_file << "    ";
            if(in_file.peek()=='\n'){
            out_file << '\n';
            in_file.ignore(1);
            }
            else out_file << "   ";
        }
        out_file << '\n';
        in_file.close();
        out_file.close();
    }
    else if(!strcmp(argv[3],"d")){

        in_file.open(argv[1]);
        if(in_file.fail())cout << "ERROR in_file" << endl;
       // ofstream out_file;
        out_file.open(argv[2]);
        if(out_file.fail())cout << "ERROR out_file" << endl;
      while(getline(in_file, temp2)){
            temp.clear();
            stringstream a1;
           while(temp2.length()>0){//
              if(temp2.find("    ")==0){
                temp.clear();
                out_file<<" ";
                temp2.erase(0,4);
                }
                else if(temp2.find(" ")!=string::npos){

                temp=temp2.substr(0,temp2.find(" "));
                temp2.erase(0,temp2.find(" ")+3);//
                }
                else {

                a1<<temp2;
                getline(a1,temp);
                //temp=temp2.substr(0,temp2.find("\n"));
                temp2.clear();
                }


                    for(int i=0; i<36; i++){
                        if(temp.compare(m[i].str)==0){
                            out_file << m[i].ch;
                         break;
                    }

                }
        }
       out_file<<"\n";

        }
        in_file.close();
        out_file.close();

    }
    return 0;
}
