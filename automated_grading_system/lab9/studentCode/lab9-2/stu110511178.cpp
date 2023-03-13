#include<bits/stdc++.h>

using namespace std;

struct stu{

    string na;
    int sc[3];
    double av;
};

void sort(stu [],int);
void sort2(stu [],int);
void swap(int* ,int*);
int main(int a, char *arg[]) {

        
    string num,k,l,n;
    int count;
    ifstream F1(arg[2]);
    l.clear();n.clear();
    n+=arg[1];
    l+=arg[2];
    
    ofstream o1(((a==3)?l+".out" : arg[3]));

    if(!F1.fail()){    

    getline(F1,num);
    count=atoi(num.c_str());
    stu dent[count];


    for(int i=0;i<count;i++){
          
        getline(F1,dent[i].na,' ');
        for(int s=0;s<2;s++){
            string x;
            getline(F1,x,' ');
            dent[i].sc[s]=atof(x.c_str());
        }
        
        getline(F1,k);
        dent[i].sc[2]=atof(k.c_str()); 
        
        
        dent[i].av=(double(dent[i].sc[0]+dent[i].sc[1]+dent[i].sc[2])/3);
    }
    
 
    



        

        
        if(!strcmp(n.c_str(),"1")){
            
            sort(dent,count);
            for(int i=0;i<count;i++){
                o1<<fixed<<setprecision(0)<<dent[i].na<<" "<<dent[i].sc[0]<<" "<<dent[i].sc[1]<<" "<<dent[i].sc[2]<<" "<<fixed<<setprecision(4)<<dent[i].av<<endl;
            }
        }
        else {
             sort2(dent,count);
             for(int i=0;i<count;i++){
                o1<<fixed<<setprecision(0)<<dent[i].na<<" "<<dent[i].sc[0]<<" "<<dent[i].sc[1]<<" "<<dent[i].sc[2]<<" "<<fixed<<setprecision(4)<<dent[i].av<<endl;
             }
        }
    

}
return 0;
}

void sort(stu dent[],int a){

    for(int i=0;i<a;i++){
        for(int k=0;k<a-1;k++){
            if(dent[k].av>dent[k+1].av){
                
                string n=dent[k].na;
            
                dent[k].na=dent[k+1].na;
                
                dent[k+1].na=n;
                swap(dent[k].sc[0],dent[k+1].sc[0]);
                swap(dent[k].sc[1],dent[k+1].sc[1]);
                swap(dent[k].sc[2],dent[k+1].sc[2]);
                double d=dent[k+1].av;
                dent[k+1].av=dent[k].av;
                dent[k].av=d;
            }
        }
    }

}

void sort2(stu dent[],int a){

    for(int i=0;i<a;i++){
        for(int k=0;k<a-1;k++){
                if(strcmp(dent[k].na.c_str(),dent[k+1].na.c_str())>0){
                
                 string n=dent[k].na;
                
                dent[k].na=dent[k+1].na;
                
                dent[k+1].na=n;
                
                swap(dent[k].sc[0],dent[k+1].sc[0]);
                swap(dent[k].sc[1],dent[k+1].sc[1]);
                swap(dent[k].sc[2],dent[k+1].sc[2]);
                 double d=dent[k+1].av;
                dent[k+1].av=dent[k].av;
                dent[k].av=d;
            

            }
        }
    }

}
void swap(int *a,int *b){
 int k=*a;
 *a=*b;
*b=k;
return;
}                 
