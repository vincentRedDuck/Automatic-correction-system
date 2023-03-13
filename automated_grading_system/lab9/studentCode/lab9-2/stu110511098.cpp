#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;

struct sheet{
    string name;
    int grade1;
    int grade2;
    int grade3;
    double avg;
};

bool scoreCmp(sheet a1,sheet a2){
    return a1.avg<a2.avg;
}

bool nameCmp(sheet a1,sheet a2){
    int i=0;
    while(a1.name[i]==a2.name[i]){
        i+=1;
    }
    return a1.name[i]-a2.name[i]<0;
}

int main(int argc,char *argv[]){
        int n;
        sheet all[100];
        ifstream in_file;
        in_file.open(argv[2]);
        in_file >> n;
        for(int i=0;i<n;i++){
            in_file>>all[i].name>>all[i].grade1>>all[i].grade2>>all[i].grade3;
            all[i].avg=(all[i].grade1+all[i].grade2+all[i].grade3)/3.0;
            //cout<<all[i].name<<" "<<all[i].grade1<<" "<<all[i].grade2<<" "<<all[i].grade3<<" "<<all[i].avg<<endl;
        }
    if(strcmp(argv[1],"1")==0){
        std::sort(all,all+n,scoreCmp);   
    }
    else{
        std::sort(all,all+n,nameCmp);
    }    
    string a;
    if(argc==3){
        a = argv[2];
        a += ".out";
    }
    else{
        a = argv[3];
    }
    ofstream out_file(a.c_str());
    for(int i=0;i<n;i++){
        out_file<<all[i].name<<" "<<all[i].grade1<<" "<<all[i].grade2<<" "<<all[i].grade3<<" "<<fixed<<setprecision(4)<<all[i].avg<<endl;
    }
    in_file.close();
    out_file.close(); 
    return 0;
}
