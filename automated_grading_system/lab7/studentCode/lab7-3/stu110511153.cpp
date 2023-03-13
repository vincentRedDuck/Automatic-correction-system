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
 int matrix1[MAXSIZE][MAXSIZE],matrix2[MAXSIZE][MAXSIZE];
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
void random(int a,int b, int matrix[][MAXSIZE])
{   
    int ran;
    for(int i=0; i<a;i++)
    {   
        for(int j=0;j<b;j++)
        {
            ran =rand()%100;
            matrix[i][j]=ran;
        }
    }
}
void showMatrix(int a,int b,int matrix[][MAXSIZE])
{
    for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cout<<left<<setw(8)<<matrix[i][j];
                if(j==b-1)
                    cout<<endl;
            }
        }
}
void mul(int matrix1[][MAXSIZE],int matrix2[][MAXSIZE],int matrix3[][MAXSIZE])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }

        }
    }
}



