#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
int mode(int,int,int,int);
int main(){
    
    int n;
    cin>>n;
    while(n>0){
        int *str=new int[n*n];
        int hf=ceil(float(n*n)/2);
        for (int i=0;i<hf;i++)
            str[i]= 2*i+1;
        for (int i=0;i<n*n-hf;i++)
            str[i+hf]=2*i+2;
        
        int **out=new int *[n];
        for(int i=0;i<n;i++)
            out[i]=new int [n];

        int md=1,r=0,c=0;
        for (int i=0;i<n*n;i++){
            out[r][c]=str[i];
            //cout<<r<<" "<<c<<endl;
//            cout<<md<<endl;
            md=mode(md,r,c,n);
            switch(md){
                case 1:
                    c++;
                break;
                case 2:
                    r+=1;
                break;
                case 3:
                    c--;
                break;
                case 4:
                    r--;
                break;
            };
        }

        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<right<<setw(5)<<out[i][j];
            cout<<endl;
        }
        for(int i=0;i<n;i++)
            delete [] out[i];
        delete  out;
        out=0;
        delete [] str;
        str=0;
        cin>>n;
    }
    return 0;
}
int mode(int md,int row,int col,int n){
    int out=md;
    float hf=float(n-1)/2;
    int k=row+col; 
    if  (row==col&&row>hf)
        return 3;
    if  ((row==col+1)&&(row<=hf))
        return 1;
    if  (k==n-1&&row<hf)
        return 2;
    if  (k==n-1&&row>hf)
        return 4;
    
    return md;
}
