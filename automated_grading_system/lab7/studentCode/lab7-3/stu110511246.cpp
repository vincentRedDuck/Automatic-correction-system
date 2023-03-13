#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXSIZE=10;
int x,y,z;
void showMatrix(int, int, int [][MAXSIZE]);
void random(int, int, int [][MAXSIZE]);
void mul (int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE],int, int, int);
int main() {
    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    cin>>x>>y;
    cout << "Please enter cols of 2nd matrix: ";
    cin>>z;
    int matrix1[MAXSIZE][MAXSIZE],matrix2[MAXSIZE][MAXSIZE];
    random(x,y,matrix1);
    random(y,z,matrix2);
    cout << "Matrix1" << endl;
    showMatrix (x,y,matrix1);
    cout << "Matrix2" << endl;
    showMatrix (y,z,matrix2);
    int matrix3[MAXSIZE][MAXSIZE]= {0};
    mul(matrix3,matrix1,matrix2,x,y,z);
    cout << "Matrix3" << endl;
    showMatrix (x,z,matrix3);
    return 0;
}
void random(int x,int y,int mtx[][MAXSIZE])
{
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            mtx[i][j]=(random()%100);
        }    
    }
}
void showMatrix(int x, int y, int mtx[][MAXSIZE])
{
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<setw(8) << left << mtx[i][j]<<((j==(y-1))?"\n":"");
        }
    }
}
void mul(int c[][MAXSIZE] ,int a[][MAXSIZE], int b[][MAXSIZE],int x,int y,int z)
{
    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
        c[i][j]=0;
        for(int k=0;k<y;k++)
            c[i][j]+=a[i][k]*b[k][j];
        }
    }   
}
