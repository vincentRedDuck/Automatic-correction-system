#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXSIZE=10;
int numrow,numcol1,numcol2;

void showMatrix(int row, int col, int mx[][MAXSIZE]){
    for(int i=0; i<=row-1; i++){
        for(int j=0; j<=col-1; j++){
            cout << mx[i][j];
            if(j != col-1) cout << "    ";
        }
    cout << endl;
    }
}


void random(int row, int col, int mx [][MAXSIZE]){
    for(int i=0; i<=row-1; i++){
        for(int j=0; j<=col-1; j++){
            mx[i][j] = rand()%100;
        }
    }
}

void mul (int in1[][MAXSIZE], int in2[][MAXSIZE], int out[][MAXSIZE]){
    for(int i=0; i<=numcol1-1; i++){
        for(int j=0; j<=numrow-1; j++){
            out[i][j] = 0;
            for(int a=0; a<=numcol2-1; a++){
                    out[i][j] += (in1[i][a] * in2[a][j]);
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
