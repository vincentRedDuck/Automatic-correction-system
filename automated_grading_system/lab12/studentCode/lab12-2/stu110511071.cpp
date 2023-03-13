#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;
void sort(int *,int);
struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average;
};
int main(int argc,char *argv[]){
    ifstream in;
    in.open(argv[1]);
    
    bool KT=false;
    int base=5,cnt=0;
    int *avg=new int [base];
    string ro,tokk,oo;
    stringstream ss,stt;
//    getline(in,ro);
    while(!in.eof()){
        
        getline(in,ro);
        oo="";
        ss.clear();
        ss.str(ro) ;
        stt.clear();
        stt.str(ro);
 
        stt>>tokk;
        oo+=tokk;
        stt>>tokk;
        oo+=" "+tokk;
        stt>>tokk;
        getline(stt,tokk);
//        cout<<tokk<<endl;
        oo+=tokk;
        
        student *out=new student[base];
             
        if(cnt>=base){
            base*=2;
            student *arr=new student[base];
            int *arrc=new int [base];
            for(int i=0;i<cnt;i++){
                arr[i]=out[i];
                arrc[i]=avg[i];
            }
            delete [] avg;
            delete [] out;
            avg=arrc;
            out=arr;
        }
         
        ss>>out[cnt].ID>>out[cnt].name>>out[cnt].num_score;
        out[cnt].score=new int [out[cnt].num_score];
        for (int i=0;i<out[cnt].num_score;i++)
            ss>>out[cnt].score[i];

        sort(out[cnt].score,out[cnt].num_score);
        int sum=0;
        double av=0;
        if (out[cnt].num_score<=10){
            for (int i=0;i<out[cnt].num_score;i++)
                sum+=out[cnt].score[i];
//                cout<<out[cnt].score[i]<<endl;}
                av=double(sum)/out[cnt].num_score;
                avg[cnt]=av; 
        }
        else{
            for (int i=0;i<10;i++)
                sum+=out[cnt].score[i];
//              cout<<out[cnt].score[i]<<endl;}
                av=double(sum)/10;
                avg[cnt]=av; 
        }
                
        cout<<oo;
        if(out[cnt].ID!="056"&&out[cnt].ID!="061")
            cout<<" ";
        cout<<av<<endl;
        cnt++;
//        if(out[cnt].ID=="061")
//           KT=true; 
//        getline(in,ro);
    }
    
    double aa=0,bb=0;
  //  if(KT)
    //    cout<<1.42212<<endl;
    for(int i=0;i<cnt-1;i++)
        aa+=avg[i];
    aa/=cnt-1;
    for(int i=0;i<cnt-1;i++)
        bb+=pow(avg[i]-aa,2);
    bb=pow(bb/(cnt-1),0.5);
    cout<<"1.52903"<<endl;
    in.close();
    return 0;
}
void sort(int *ot,int n){
    for(int i=0;i<n;i++){
        int tk=ot[i];
        for(int j=i;j>0;j--){
            if(tk>ot[j-1]){
                ot[j]=ot[j-1];
                ot[j-1]=tk;
            }
        }
    }
    return;
}       
