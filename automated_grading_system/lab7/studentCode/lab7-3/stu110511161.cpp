#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE=10;
int numrow,numcol1,numcol2;

void showMatrix(int row, int col, int array[10][MAXSIZE]){
    for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
            cout << setw(8) << left << array[i][j];
        }
        cout << endl;
    }
}

void random(int row, int col, int array[10][MAXSIZE]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            array[i][j]=rand()%100;
        }
    }
}

void mul (int v1[10][MAXSIZE], int v2[10][MAXSIZE], int v3[10][MAXSIZE]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                v3[i][j]+=v1[i][k]*v2[k][j];
            }
        }
    }
}


int main(){
 srand(2001); 
 cout << "Please enter rows and cols of 1st matrix: ";
cin>>numrow>>numcol1;
cout << "Please enter cols of 2nd matrix: ";
cin>>numcol2;
 int matrix1[MAXSIZE][MAXSIZE]={0},matrix2[MAXSIZE][MAXSIZE]={0};
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
