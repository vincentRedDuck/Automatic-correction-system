#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

const int MAXSIZE = 10;
int numrow, numcol1, numcol2;

void showMatrix(int row, int col, int matrix[10][MAXSIZE]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << left << setw(8) << matrix[i][j];
        }
        cout << endl;
    }
}

void random(int row, int col, int matrix[10][MAXSIZE]){
     for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = rand()%100;
        }
    }
}

void mul(int m1[10][MAXSIZE],int m2[10][MAXSIZE],int m3[10][MAXSIZE]){
     for(int i=0; i<numrow; i++){
        for(int j=0; j<numcol2; j++){
            for(int k=0; k<numcol1; k++){
                m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
}

int main(){
    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    cin >> numrow >> numcol1;
    cout << "Please enter cols of 2nd matrix: ";
    cin >> numcol2;
    int matrix1[10][10],matrix2[10][10];
    random(numrow,numcol1,matrix1);
    random(numcol1,numcol2,matrix2);
    cout << "Matrix1" << endl;
    showMatrix(numrow,numcol1,matrix1);
    cout << "Matrix2" << endl;
    showMatrix(numcol1,numcol2,matrix2);
    int matrix3[10][10] = {0};
    mul(matrix1,matrix2,matrix3);
    cout << "Matrix3" << endl;
    showMatrix(numrow,numcol2,matrix3);
    return 0;
}
