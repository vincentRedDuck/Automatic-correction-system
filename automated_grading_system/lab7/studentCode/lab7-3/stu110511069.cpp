#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXSIZE=10;
int numrow,numcol1,numcol2;
void showMatrix(int , int, int [][MAXSIZE]);
void random(int, int, int [][MAXSIZE]);
void mul (int,int,int,int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE]);
int main(){
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
    int matrix3[MAXSIZE][MAXSIZE]={0};
    mul(numrow,numcol1,numcol2,matrix1,matrix2,matrix3);
    cout << "Matrix3" << endl;
    showMatrix (numrow,numcol2,matrix3);
    return 0;
}
void random(int row, int col, int Mat[][MAXSIZE]){
    for(int i =0;i<row;i++){
        for(int j= 0;j<col;j++){
            Mat[i][j] = rand()%100;
        }
    }
}



void mul (int a,int b,int c,int A[][MAXSIZE], int B[][MAXSIZE], int Mat[][MAXSIZE]){
    for(int i=0;i<c;i++){
        for(int j =0;j<a;j++){
            Mat[j][i] = 0;
            for(int k=0;k<b;k++){
                Mat[j][i] += A[j][k] * B[k][i];
            }
        }
    }
}


void showMatrix(int row,int col, int Mat [][MAXSIZE]){
    for(int i =0;i<row;i++){
        for(int j= 0;j<col;j++){
           cout<<left<<setw(8)<<Mat[i][j];
        
        }
        cout<<endl;
    }

}
