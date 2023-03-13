#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    int y,x;
    cin>>n;
    while(n!=-1){
        x =0;
        y =0;
        int cur = 1;
        int **arr = new int* [n];
        for(int i =0;i<n;i++){
            arr[i] = new int[n];
        }
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                arr[i][j]=0;
            }
        }
        int c =0;

        while(c<n*n){

            while(x<n&&arr[y][x]==0){
                if(cur>n*n)cur = 2;
                arr[y][x]=cur;
                x++;
                cur += 2;
                c++;
            }
            x -=1;
            y+=1;

            while(y<n&&arr[y][x]==0){
                if(cur>n*n)cur = 2;
                arr[y][x]=cur;
                y++;
                cur += 2;
                c++;
            }
            y -=1;

            x -=1;
            while(x>=0&&arr[y][x]==0){
                if(cur>n*n)cur = 2;
                arr[y][x]=cur;
                x--;
                cur += 2;
                c++;
            }
            x +=1;
            
            y-=1;
            while(y>=0&&arr[y][x]==0){
                if(cur>n*n)cur = 2;
                arr[y][x]=cur;
                y--;
                cur += 2;
                c++;
            }
            y+=1;
            x+=1;

        }
        
        
        
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                cout<<setw(5)<<right<<arr[i][j];
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            delete [] arr[i];
        }
        delete [] arr;
        cin>>n;
    }
    return 0;
}
