#include<bits/stdc++.h>

using namespace std;
int** fill(int**,double);
int main(){
double wid;
int reg=1;

    while(cin>>wid){
        int **num=new int*[int(ceil(wid/2))];
        for(int r=0;r<ceil(wid/2);r++) num[r]=new int[int(pow((wid-r*2),2)-pow((wid-r*2-2),2))];
        for(int r=0;r<ceil(wid/2);r++){
                      for(int i=0;i<pow((wid-r*2),2)-pow((wid-r*2-2),2);i++){
                num[r][i]=reg;
                reg+=2;
                if(reg>pow(wid,2))reg=2;
            }
        }
                
        int** graph=new int*[int(wid)];
        graph=fill(num,wid);
         if(int(wid)%2==1)graph[int(floor(wid/2))][int(floor(wid/2))]=pow(wid,2)-1;

        for(int i=0;i<wid;i++){
            for(int k=0;k<wid;k++)
            cout<<right<<setw(5)<<graph[i][k];
            cout<<endl;
       }
        reg=1;      

        }

return 0;
}

int** fill(int **num,double wid){
    
    int **graph=new int *[int(wid)];
    for(int y=0;y<wid;y++)graph[y]=new int[int(wid)];
    
    
    int y,x,count=0;
    for(int i=0;i<ceil(wid/2);i++){
          x=i;
          y=i;
        count=0; 
            for(int s=0;s<=wid-i*2-1;s++,x++,count++){
                graph[y][x]=num[i][count];
            }
            x--;    
            y++;    
            for(int k=0;k<wid-i*2-1;k++,y++,count++){
                graph[y][x]=num[i][count];
            }
            y--;
            x--;
             for(int k=0;k<wid-i*2-1;k++,x--,count++){
                graph[y][x]=num[i][count];
            }   
            x++;
            y--;
            for(int k=0;k<wid-i*2-2;k++,y--,count++){
                graph[y][x]=num[i][count];
            }
    }
return graph;
}
    




