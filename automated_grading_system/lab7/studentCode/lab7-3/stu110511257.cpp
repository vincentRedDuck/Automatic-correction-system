#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXSIZE=10;
int numrow,numcol1,numcol2;
void showMatrix(int r, int c , int m[][MAXSIZE]) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
          if (j!=c-1)
            cout << setw(8) << left << m[i][j];
          else
            cout << m[i][j] << endl;
        } 
    }  
}
void random(int r, int c, int m[][MAXSIZE]) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            m[i][j] = rand()%100;
        } 
    }
}
void mul (int m1[][MAXSIZE], int m2[][MAXSIZE], int m3[][MAXSIZE]) {
    for (int i=0; i<MAXSIZE; i++) {
        for (int j=0; j<MAXSIZE; j++) {
            for (int k=0; k<MAXSIZE; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    } 
}
int main()
{
    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    cin>>numrow>>numcol1;
    cout << "Please enter cols of 2nd matrix: ";
    cin>>numcol2;
    int matrix1[MAXSIZE][ MAXSIZE],matrix2[MAXSIZE][ MAXSIZE];
    random(numrow,numcol1,matrix1);
    random(numcol1,numcol2,matrix2);
    cout << "Matrix1" << endl;
    showMatrix (numrow,numcol1,matrix1);
    cout << "Matrix2" << endl;
    showMatrix (numcol1,numcol2,matrix2);
    int matrix3[MAXSIZE][MAXSIZE]= {0};
    mul(matrix1,matrix2,matrix3);
    cout << "Matrix3" << endl;
    showMatrix (numrow,numcol2,matrix3);
    return 0;
}
