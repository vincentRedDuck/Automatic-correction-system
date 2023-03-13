#include<bits/stdc++.h>

using namespace std;
struct student{

    string id;
    string name;
    int *score;
    int numscore;
    double average;
};

int main(int k,char **argv){

ifstream f1(argv[1]);
int count=0;
string tok;
while(getline(f1,tok))count++;
f1.close();


    student* st=new student[count];

    f1.open(argv[1]);
    
    string reg;
    int stn=0;
    while(getline(f1,reg)){
        stringstream ss(reg);

        ss>>st[stn].id>>st[stn].name>>st[stn].numscore;
        cout<<st[stn].id<<" "<<st[stn].name<<" ";
        st[stn].score=new int[st[stn].numscore];
        int total=0,c=0;
        for(int i=0;i<st[stn].numscore;i++){
            ss>>st[stn].score[i];
            cout<<st[stn].score[i]<<" ";
            
        }
        for(int i=10;i>=0;i--){
            for(int y=0;y<st[stn].numscore;y++){
                if(st[stn].score[y]==i){
                    total+=st[stn].score[y];
                    c++;
                    
                }
                if(c==10)break;
            }
            if(c==10)break;
        }
        st[stn].average=double(total/double(c));
        cout<<st[stn].average<<endl;
        stn++;
    }

double l=0,p=0;

    for(int i=0;i<stn;i++ )
            l+=st[i].average;
    l/=stn;

    for(int i=0;i<stn;i++)
        p+=pow((st[i].average-l),2);
        p/=stn;
    cout<<sqrt(p)<<endl;
    
    
    



return 0;
}
