#include <iostream>
#include <iomanip>
using namespace std;

void fill_in(int n,int k ,int& a, int& b ,int **pos,int& num);

int main()
{
    int p;
    cin >> p;
    while(p!=(-1))
    {
        int q = p;

        int **vec = new int *[p];
        for (int i = 0;i < p; i++)
            vec[i] = new int [p];

        int m=0;
        int n=0;
        int h=1;
        for(int i=p;i>0;i--)
        {
            fill_in(p,i,m,n,vec,h);
            
        }

        for(int i= 0; i<p; i++)
        {
            for(int j= 0; j<p; j++)
            {
                cout << right << setw(5)<< vec[i][j] ;
            }
            cout << endl;
        }

        for (int idx = 0; idx < p; idx++)
            delete [] vec[idx];
        delete []vec; 

        cin >> p;
    }
    return 0;
}

void fill_in(int n ,int k ,int& a, int& b ,int **pos,int& num)
{
    /*if(k==0)
        return;*/
    if(k==n)
    {
        for(int i= a; i<k; i++)
        {
            pos[a][i]=num;
            num+=2;
            if(num==(n*n+1)||num==(n*n+2))
                 num = 2;
            //num+=2;
            b = i;
        }
        //fill_in(n,k-1,a,b,pos,num);
    }
    else if((n-k)%2==1)
    {
        int aa = a+k;
        int bb = b-k;
        for(int i= a+1; i<=(aa); i++)
        {
            pos[i][b] = num ;
            num += 2;
            if(num==(n*n+1)||num==(n*n+2))
                num = 2;
            //num+=2;
            a = i;
        }
        for(int j= b-1; j>=(bb); j--)
        {
            pos[a][j] = num;
            num += 2;
            if(num==(n*n+1)||num==(n*n+2))
                num = 2;
            //num+=2;
            b = j;
        }
        //fill_in(n,k-1,a,b,pos,num);
    }
    else
    {
        int aa = a-k;
        int bb = b+k;
        for(int i= a-1; i>=(aa); i--)
        {
            pos[i][b] = num ;
            num += 2;
            if(num==(n*n+1)||num==(n*n+2))
                num = 2;
            //num+=2;
            a=i;
        }
        for(int j= b+1; j<=(bb); j++)
        {
            pos[a][j] = num;
            num += 2;
            if(num==(n*n+1)||num==(n*n+2))
                num = 2;
            //num+=2;
            b=j;
        }
        //fill_in(n,k-1,a,b,pos,num);

    }

}
