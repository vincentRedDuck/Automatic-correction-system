#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int dx[4] = {0,1,0,-1} , dy[4]  = {1,0,-1,0};
    int size;//x=size
    while(cin>>size){
        int mode = ( (size%2==0) ? 1 : 0 );
        if(size==-1){
            break;
        }
        int **v = new int*[size];
        for(int i=0;i<size;i++){
            v[i] = new int[size];
        }
        int index = 0, x=0,y=-1, lx, ly;
        int num = 1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                v[i][j]=0;
            }
        }
        for(int i=0;i<size*size;i++){
            lx = x+dx[index];
            ly = y+dy[index];
            if( lx<0 || lx>size-1 || ly<0 || ly>size-1 || v[lx][ly]!=0){
                index = (index+1)%4;
            }
            x = x + dx[index]; y = y + dy[index];
            v[x][y] = num; 
            if(mode == 1){
                if(num == size*size-1)  num = 0;
            }
            else
                if(num == size*size)  num=0;
            num+=2;
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<setw(5)<<right<<v[i][j];
            }
            cout<<endl;
        }
        for(int i=0;i<size;i++){
            delete [] v[i];
        }
        delete [] v; v=NULL;
    }

    
    return 0;
}
