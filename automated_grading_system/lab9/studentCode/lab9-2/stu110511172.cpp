#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

struct score{
    string name;
    int sc1,sc2,sc3;
    double avg;
};
void sort1(score x[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            score temp;
            if((x[j].avg>x[j+1].avg)&&j<len-1){
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;}
        }
    }

}
void sort2(score x[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            score temp;
            if((x[j].name>x[j+1].name)&&j<len-1){
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;}
        }
    }
}

int main(int argc,char *argv[]){
    char outfile[20] = {};
    if(argc>3){
    strcpy(outfile, argv[3]);}
    else{
    outfile[20];
    strcpy(outfile,argv[2]);
    strcat(outfile,".out");
    }
    cout << outfile<<endl;
        
    ifstream fin(argv[2]);
    ofstream fout(outfile);
    string line;
    int stu;
    getline(fin,line);
    stu = stoi(line);
    
    score file[100];
    char ch;
    int t=0;
    for(int i=0;i<stu;i++){
        fin >> file[i].name>>file[i].sc1>>file[i].sc2>>file[i].sc3;
        file[i].avg = (file[i].sc1+file[i].sc2+file[i].sc3)/3.0;
        getline(fin,line);
    }
    int type = atoi(argv[1]);
    if(type==1)
        sort1(file,stu);
    else
        sort2(file,stu);
    for(int i=0;i<stu;i++){
    fout << file[i].name << " " << file[i].sc1 << " " << file[i].sc2 << " " << file[i].sc3 << " " << fixed << setprecision(4)<< file[i].avg<<endl;
    }
    
    return 0;
}
