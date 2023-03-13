#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAXSIZE=10;

int numrow,numcol1,numcol2;

void showMatrix(int r, int c, int arr[][MAXSIZE]) {
  for (int row = 0; row < r; ++row) {
    for (int col = 0; col < c; ++col) {
      if (col == c - 1) {
        cout << arr[row][col];
      }
      else {
        cout << setw(8) << left << arr[row][col];
      }
    }
    cout << "\n";
  }
}

void random(int r, int c, int arr[][MAXSIZE]) {
  for (int row = 0; row < r; ++row) {
    for (int col = 0; col < c; ++col) {
      arr[row][col] = rand() % 100;
    }
  }
}

void mul (int a[][MAXSIZE], int b[][MAXSIZE], int c[][MAXSIZE]) {
  for (int row = 0; row < MAXSIZE; ++row) {
    for (int col = 0; col < MAXSIZE; ++col) {
      int sum = 0;
      for (int t = 0; t < MAXSIZE; ++t){
        sum += a[row][t] * b[t][col];
      }
      c[row][col] = sum;
    }
  }
}

int main(){
  srand(2001);
  cout << "Please enter rows and cols of 1st matrix: ";
  cin >> numrow >> numcol1;
  cout << "Please enter cols of 2nd matrix: ";
  cin >> numcol2;
  int matrix1[MAXSIZE][ MAXSIZE],matrix2[MAXSIZE][ MAXSIZE];

  random(numrow,numcol1,matrix1);
  random(numcol1,numcol2,matrix2);

  cout << "Matrix1" << endl;
  showMatrix (numrow,numcol1,matrix1);
  cout << "Matrix2" << endl;
  showMatrix (numcol1,numcol2,matrix2);

  int matrix3[MAXSIZE][MAXSIZE] = {0};
  mul(matrix1,matrix2,matrix3);
  cout << "Matrix3" << endl;
  showMatrix (numrow,numcol2,matrix3);
  return 0;
}
