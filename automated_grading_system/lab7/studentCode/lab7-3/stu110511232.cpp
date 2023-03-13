#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXSIZE=10;
int numrow,numcol1,numcol2;
void showMatrix(int , int, int [][MAXSIZE]);
void random(int, int, int [][MAXSIZE]);
void mul (int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE]);

int main(){
    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    cin>>numrow>>numcol1;
    cout << "Please enter cols of 2nd matrix: ";
    cin>>numcol2;
    int matrix1[MAXSIZE][ MAXSIZE]={0},matrix2[MAXSIZE][ MAXSIZE]={0};
    random(numrow,numcol1,matrix1);
    random(numcol1,numcol2,matrix2);
    cout << "Matrix1" << endl;
    showMatrix (numrow,numcol1,matrix1);
    cout << "Matrix2" << endl;
    showMatrix (numcol1,numcol2,matrix2);
    int matrix3[MAXSIZE][MAXSIZE]={0};
    mul(matrix1,matrix2,matrix3);
    cout << "Matrix3" << endl;
    showMatrix (numrow,numcol2,matrix3);
    return 0;
}

void showMatrix(int r, int c, int m[][MAXSIZE])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<m[i][j];
            if(j!=c-1)
            {
                cout<<"      ";
            }
            else
            {
                cout<<endl;
            }
        }
    }
}

void random(int r, int c, int m[][MAXSIZE])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j]=rand()%100;
        }
    }
}

void mul (int m1[][MAXSIZE], int m2[][MAXSIZE], int m3[][MAXSIZE])
{
    for(int i=0;i<MAXSIZE;i++)
    {
        for(int j=0;j<MAXSIZE;j++)
        {
            int s=0;
            for(int k=0;k<MAXSIZE;k++)
            {
                s+=m1[i][k]*m2[k][j];
            }
            m3[i][j]=s;
        }
    }
}
