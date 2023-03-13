#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

void prt(int **mtx,int a_size)
{
    for(int i=0;i<a_size;i++)
    {
        for(int j=0;j<a_size;j++)
        {
            cout<<setw(5)<<right<<mtx[i][j];
            if(j==a_size-1)
            {
                cout<<endl;
            }
        }
    }
}

void fill(int** mtx,int a_size,int max_odd,int max_even)
{
    int up=0;
    int down=a_size;
    int left=0;
    int right=a_size;
    int digit=1;
    int r=0;
    int c=0;

    while(digit<=max_odd)
    {
        mtx[r][c]=digit;
        if((r==up)&&(c<right-1))
        {
           c+=1;
        }
        else if((c==right-1)&&(r<down-1))
        {
           r+=1;
        }
        else if((r==down-1)&&(c>left))
        {
            c-=1;
        }
        else if((c==left)&&(r>up+1))
        {
            r-=1;
        }
        else if((r==up+1)&&(c==left))
        {
            up+=1;
            left+=1;
            down-=1;
            right-=1;
            c+=1;
        }
        digit+=2;
    }

    
    digit=2;
    while(digit<=max_even)
    {
        mtx[r][c]=digit;
        if((r==up)&&(c<right-1))
        {
            c+=1;
        }
        else if((c==right-1)&&(r<down-1))
        {
            r+=1;
        }
        else if((r==down-1)&&(c>left))
        {
            c-=1;
        }
        else if((c==left)&&(r>up+1))
        {
            r-=1;
        }
        else if((r==up+1)&&(c==left))
        {
            up+=1;
            left+=1;
            down-=1;
            right-=1;
            c+=1;
        }
        digit+=2;
    }
 
}

int main()
{
    int a_size;
    cin>>a_size;
    while(a_size!=-1)
    {
        int max_odd=(a_size%2==0) ? a_size*a_size-1 : a_size*a_size;
        int max_even=(a_size%2==0) ? a_size*a_size : a_size*a_size-1;
        int** mtx=new int* [a_size];
        for(int i=0;i<a_size;i++)
        {
            mtx[i]=new int [a_size];
        }
        fill(mtx,a_size,max_odd,max_even);
        prt(mtx,a_size);
        cin>>a_size;
    }
    return 0;
}
