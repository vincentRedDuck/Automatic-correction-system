#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n!=-1)
    {
        int **arr=new int*[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=new int [n];
        }
        int colmax=n-1,colmin=0,rowmax=n-1,rowmin=0;
        int x=0,y=0,xv=1,yv=0;
        for(int i=1;i<=n*n;i+=2)
        {
            arr[y][x]=i; 
            if(x+xv>colmax)
            { 
                xv=0;
                yv=1;
                rowmin+=1;
            }
            if(y+yv>rowmax)
            {
                xv=-1;
                yv=0;
               colmax-= 1;
            }
            if(y+yv<rowmin)
            {
                yv=0;
                xv=1;
                colmin+=1;
            }
            if(x+xv<colmin)
            {
                xv=0;
                yv=-1;
                rowmax-=1;
            }
            x+=xv;
            y+=yv;
        }
        for(int i=2;i<=n*n;i+=2)
        {
            arr[y][x]=i; 
            if(x+xv>colmax)
            { 
                xv=0;
                yv=1;
                rowmin+=1;
            }
            if(y+yv>rowmax)
            {
                xv=-1;
                yv=0;
               colmax-= 1;
            }
            if(y+yv<rowmin)
            {
                yv=0;
                xv=1;
                colmin+=1;
            }
            if(x+xv<colmin)
            {
                xv=0;
                yv=-1;
                rowmax-=1;
            }
            x+=xv;
            y+=yv;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<setw(5)<<right<<arr[i][j];
            }
            cout<<endl;
        }
    }
}
