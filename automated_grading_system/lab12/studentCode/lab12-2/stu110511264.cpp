#include<bits/stdc++.h>
using namespace std;
struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 scores average
};
int main(int argc, char *argv[]){
    ifstream f;
    f.open(argv[1]);
    int num=0;
    string garbage;
    while(getline(f, garbage)){
    //getline(f,garbage);
    num++;
    /*if(f.eof())
        break;*/
    }
    ifstream fin;
    fin.open(argv[1]);
    student *stu;
    stu = new student [num];
    for(int i=0;i<num;i++){
        fin>>stu[i].ID>>stu[i].name>>stu[i].num_score;
        cout<<stu[i].ID<<" "<<stu[i].name;
        stu[i].score = new int [stu[i].num_score];
        int n=0;
        while(fin>>stu[i].score[n]){
            //fin>>stu[i].score[n];
            cout<<" "<<stu[i].score[n];
            n++;
            if(n==stu[i].num_score)
                break;
        }
        //cout<<"\n"<<n<<"\n";
        if(n<11){
            double sum=0.0;
            for(int j=0;j<stu[i].num_score;j++){
                sum+=stu[i].score[j];
            }
            stu[i].average=sum/double(stu[i].num_score);
            cout<<" "<<stu[i].average;
        }
        else{
            for(int j=stu[i].num_score;j>0;j--){
                for(int k=0;k<j-1;k++){
                    if(stu[i].score[k]>stu[i].score[k+1]){
                        swap(stu[i].score[k],stu[i].score[k+1]);
                    }
                }
            }
            double sum=0.0;
            for(int j=stu[i].num_score-1;j>stu[i].num_score-11;j--){
                sum+=stu[i].score[j];
            }
            stu[i].average=sum/10;
            cout<<" "<<stu[i].average;
        }
            cout<<"\n";
    }
    double totalsum=0,totalaverage=0;
    for(int i=0;i<num;i++){
        totalsum+=stu[i].average;
    }
    totalaverage=totalsum/num;
    double difsqusum=0;
    for(int i=0;i<num;i++){
        difsqusum+=pow(stu[i].average-totalaverage,2);
    }
    cout<<pow((difsqusum/num),0.5)<<"\n";
    return 0;
}
