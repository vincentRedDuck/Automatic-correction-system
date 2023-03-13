#include<bits/stdc++.h>
using namespace std;

void showMatrix(int length, int width ,int arr[10][10])
{
     for(int i=0;i<length;i++)
    {
        for(int j=0;j<width;j++)
       { cout<<left<<setw(8)<<arr[i][j];}
        cout<<endl;
    }
}

void random(int length , int width , int arr[10][10])
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<width;j++)
        arr[i][j]=rand()%100;
    }

}

void mul(int m1[10][10],int m2[10][10],int m3[10][10])
{
    int sum;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            sum=0;
            for(int k=0;k<10;k++)
            {sum+=m1[i][k]*m2[k][j];}
            m3[i][j]=sum;
            
        }
    }

}

int main()
{
    int a,b,c;
    srand(2001);
    cout<<"Please enter rows and cols of 1st matrix: ";
    cin>>a>>b;
    cout<<"Please enter cols of 2nd matrix: ";
    cin>>c;
    int m1[10][10]={0},m2[10][10]={0};
    random(a,b,m1);
    random(b,c,m2);
    cout<<"Matrix1"<<endl;
    showMatrix(a,b,m1);
    cout<<"Matrix2"<<endl;
    showMatrix(b,c,m2);
    int m3[10][10]={0};
    mul(m1,m2,m3);
    cout<<"Matrix3"<<endl;
    showMatrix(a,c,m3);
    return 0;
}
