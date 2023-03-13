#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct pokemon{
    string num;
    string eng;
    string tch;
    int n;
};

struct my{
    int num;
    string eng;
};

int main(int argc, char *argv[]){
    ifstream file1,file3;
    ofstream file2,file4;
    stringstream ss;
    string rfile1 = argv[1], rfile2 = argv[3], wfile1 = argv[2], wfile2 = argv[4];
    string str, a;
    struct pokemon pok[493];
    int i = 0, j = 0, k = 0;

    file1.open(rfile1);
    file2.open(wfile1, ios::out);
    while(getline(file1,str)){
        ss.str(str);
        ss >> pok[i].num;
        ss >> a;
        ss >> pok[i].eng;
        ss >> pok[i].tch;
        file2 << pok[i].num << " " << pok[i].eng << " " << pok[i].tch << endl;
        pok[i].n = i+1;
        i++;
    }
    file1.close();
    file2.close();
    
    file3.open(rfile2);
    file4.open(wfile2, ios::out);
    while(file3 >> str){
        j++;
        //cout << str << endl;
    }
    file3.close();
    file3.open(rfile2);
    struct my mypok[j], temp;
    while(file3 >> str){
        if(str.length() == 1){
            str = '0'+str;
            str = '0'+str;
        }
        else if(str.length() < 3){
            str = '0'+str;
        }
        for(i = 0; i < 493; i++){
            if(str == pok[i].num || str == pok[i].eng ){
                mypok[k].num = i+1;
                mypok[k].eng = pok[i].eng;
                //cout << i+1 << endl;
                break;
            }
        }
        k++;
    }
    for(i = 0; i < j; i++){
        for(k = 0; k < j; k++){
            if(mypok[i].num < mypok[k].num){
                temp.num     = mypok[i].num;
                mypok[i].num = mypok[k].num;
                mypok[k].num = temp.num;
                temp.eng     = mypok[i].eng;
                mypok[i].eng = mypok[k].eng;
                mypok[k].eng = temp.eng;
            }
        }
    }
    for(i = 0; i < j; i++){
        if(mypok[i].num != mypok[i-1].num){
            file4 << mypok[i].num << " " <<  mypok[i].eng << endl;
        }
    }
    file3.close();
    file4.close();
    return 0;
}
