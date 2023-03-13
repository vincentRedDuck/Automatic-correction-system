#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        int num=1;
        int dir=0,cnt=0,i=0,j=0;
        cin>>n;
        if(n==-1) return 0;
        int **vec=new int *[n];
        for(int i=0;i<n;i++){
            vec[i]=new int [n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vec[i][j]=0;
            }
        }
        while(cnt<pow(n,2)){
                vec[i][j]=num;
                /*cout<<i<<"\n"<<j<<"\n"<<"\n";*/
                /*for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        cout<<vec[k][l]<<" ";
                }
                cout<<"\n";
                }*/
                num +=2;
                if((i==n-1&&j==n-1)||(j==0&&i==n-1)||(i==0&&j==n-1)){
                    dir++;
                    dir=dir%4;
                }
                else if(dir==0&&vec[i][j+1]!=0){
                    dir++;
                    dir=dir%4;
                }
                else if(dir==1&&vec[i+1][j]!=0){
                    dir++;
                    dir=dir%4;
                }
                else if(dir==2&&vec[i][j-1]!=0){
                    dir++;
                    dir=dir%4;
                }
                else if(dir==3&&vec[i-1][j]!=0){
                    dir++;
                    dir=dir%4;
                }
                cnt++;
                if(dir==0){
                    j++;
                }
                else if(dir==1){
                    i++;
                }
                else if(dir==2){
                    j--;
                }
                else if(dir==3){
                    i--;
                }
                if(num>n*n){
                    num=2;
                }
                
        }
                    for(int k=0;k<n;k++){
                        for(int l=0;l<n;l++){
                            cout<<right<<setw(5)<<vec[k][l];
                }
                cout<<"\n";
                }
    }
}
