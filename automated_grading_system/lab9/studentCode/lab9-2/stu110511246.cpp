#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
const int Max=10;
struct score{
    string name;
    int sub[3];
    double avg;
};
//void sort(score[],int ,int);
int main(int argc, char **argv){
    score stu[Max];
    int opt(atoi(argv[1]));
    ifstream fin(argv[2]);
    string fName((argc==4)?string(argv[3]):(string(argv[2])+".out"));
    ofstream fout(fName.c_str());

    int num;
    fin>>num;
    for (int i=0;i<num;i++){
        fin>>stu[i].name>>stu[i].sub[0]>>stu[i].sub[1]>>stu[i].sub[2];
        stu[i].avg=(stu[i].sub[0]+stu[i].sub[1]+stu[i].sub[2])/3.0;
    }
   // sort(stu,num,opt);
    if(stoi(argv[1])==1){
        for(int i=0;i<num-1;i++){
            for(int j=0;j<num-1-i;j++){
                if(stu[j].avg>stu[j+1].avg){
                    score tmp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=tmp;
                }
            }
        }
    }
    else{
        for(int i=0;i<num-1;i++){
            for(int j=0;j<num-1-i;j++){
                if(stu[j].name>stu[j+1].name){
                    score tmp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=tmp;
                }
            }
        }
    }
    for(int i=0;i<num;i++){
        fout<<stu[i].name<<" "<<stu[i].sub[0]<<" "<<stu[i].sub[1]<<" "<<stu[i].sub[2]<<" "<<fixed<<setprecision(4)<<stu[i].avg<<endl;

    }
    fin.close();fout.close();
    return 0;
}
/*bool bigger(score x,score y,int cmp){
    return ((cmp==1)?(x.name>y.name):(x.avg>y.avg));
}
void sort(score vec[],int len,int cmp){
    for(int j=1;j<len;j++){
        score key(vec[j]);
        int i=j-1;
        while((i>=0)&&(bigger(vec[i],key,cmp))){
            vec[i+1]=vec[i];
            i--;
        }
        vec[i+1]=key;
    }
}*/
