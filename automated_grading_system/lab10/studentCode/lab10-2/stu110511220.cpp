#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

struct Pok {
    string index;
    string Eng;
    string Tai;
};

void comparison(string ,Pok* ,bool* ,int&);
void insertionsort(Pok* ,int);

int main (int argc ,char **argv) {
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    int size=0;
    //string str;
    //while(getline(inFile,str))
    //    size++;
    Pok pokedex[494];
    inFile.close();

    inFile.open(argv[1]);
    string line, tok;
    int i=0;
    while(getline(inFile,line)) {
        stringstream ss(line);
        ss >> pokedex[i].index >> tok >> pokedex[i].Eng >> pokedex[i].Tai ;
        outFile << pokedex[i].index << " " << pokedex[i].Eng << " " << pokedex[i].Tai << endl;
        i++;
    }
    inFile.close();
    outFile.close();

    inFile.open(argv[3]);
    outFile.open(argv[4]);
    string line1;
    // 是否有那隻寶可夢
    bool myPokemon[494];
    for (int i =0;i<494;i++){
        myPokemon[i] = false;
    }
    int j=0;
    while(getline(inFile,line1)) {
        stringstream ss(line1);
        string line2;
        while(ss>>line2) {

            if(isalnum(line2[0])) {
                comparison(line2,pokedex,myPokemon,j);   //j==the number of my Pokemon;
            }
        }
    }
    //j--;
    for(int i =0;i<494;i++){

        if(myPokemon[i]) outFile<<i<<" "<<pokedex[i-1].Eng<<endl;

    }
    inFile.close();
    outFile.close();

    return 0;
}

void comparison(string line,Pok *pokedex,bool *myPokemon ,int &j) {

    if(isalpha(line[0])) {
        for(int i=0;i<493;i++) {
            if(line==pokedex[i].Eng) {
                //字典檔的位址比ID少一,補回去
                myPokemon[i+1]  = true;
                return ;
            }
        }
    }
    else if(isdigit(line[0])) {
        for(int i=0;i<493;i++) {
            if(atoi(line.c_str())==atoi((pokedex[i].index).c_str())) {
                myPokemon[i+1]= true;
                return ;
            }
        }
    }
}
/*
void insertionsort(Pok *myPokemon,int size) {
    for(int j=1;j<size;j++) {
        Pok key=myPokemon[j];
        int i=j-1;
        while(i>=0&&atoi((myPokemon[i].index).c_str())>atoi((key.index).c_str())) {
            myPokemon[i+1]=myPokemon[i];
            i--;
        }
        myPokemon[i+1]=key;
    }
}*/
