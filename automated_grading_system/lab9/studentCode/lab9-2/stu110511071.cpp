#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<cstring>
#include<iomanip>
using namespace std;
struct grade{
    char name[16];
    int g1;
    int g2;
    int g3;
    float avg;
    };

int main(int argc, char *argv[]){
    string str1,str2;
        str1=argv[2];
    if (argc==4)
        str2=argv[3];
    else if (argc==3)
        str2=str1+".out";
    string mode= argv[1];
 
    grade gra[100];
    for (int i=0;i<101;i++){
        for(int j=0;j<=16;j++)
            gra[i].name[j]='\0';
        gra[i].avg=0;
    }
    ifstream infile;
    ofstream outfile;
    infile.open(str1.c_str());
    outfile.open(str2.c_str(),ios::out);
    
    int total;
    infile>>total;
    for (int i=0;i<total;i++){
        infile>>gra[i].name;
        infile>>gra[i].g1;
        infile>>gra[i].g2;
        infile>>gra[i].g3;
        gra[i].avg=float(gra[i].g1+gra[i].g2+gra[i].g3)/3;
    }/*
    cout<<argc<<endl<<argv[2]<<endl<<argv[3]<<endl;
    */
    if(mode=="1"){
        grade tran;
        for (int i=1;i<total;i++){
            tran=gra[i];
            for (int j=i;j>0;j--){
                if(tran.avg<gra[j-1].avg){
                    gra[j]=gra[j-1];
                    gra[j-1]=tran;
                }
                else{
                    gra[j]=tran;
                    break;
                }
            }
        }
    }
    if(mode=="2"){
        grade tran;
        for (int i=1;i<total;i++){
            tran=gra[i];
            for (int j=i;j>0;j--){
                if(strcmp(tran.name,gra[j-1].name)<0){
                    gra[j]=gra[j-1];
                    gra[j-1]=tran;
                }
                else{
                    gra[j]=tran;
                    break;
                }
            }
        }
    }  
    for (int i=0;i<total;i++){
        outfile<<gra[i].name<<" "<<gra[i].g1<<" "<<gra[i].g2<<" "<<gra[i].g3<<" ";
        outfile<<fixed<<setprecision(4)<<gra[i].avg<<endl;  
    }
    infile.close();
    outfile.close();
    return 0;
}
