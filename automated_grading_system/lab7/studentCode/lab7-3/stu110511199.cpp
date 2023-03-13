#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX = 100;
void showMtx(int [][MAX], int , int );
void initMtx(int [][MAX], int , int );
void showMtx2(int [][MAX], int , int );
void multiply(int [][MAX], int [][MAX], int [][MAX], int, int, int );

int main() {
    int x, y, z;
    int m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX];
    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    cin >> x >> y;
    cout << "Please enter cols of 2nd matrix: ";
    cin >> z;

    initMtx(m1, x, y); cout << "Matrix1" << endl;
    showMtx2(m1, x, y);
    initMtx(m2, y, z); cout << "Matrix2" << endl;
    showMtx2(m2, y, z);
    multiply(m1, m2, m3, x , y, z); cout << "Matrix3" << endl;
    showMtx2(m3, x, z) ;
 
    return 0;
}

void initMtx(int mtx[][MAX], int r, int c) {
    for(int i=0;i<r; i++){
        for(int j=0; j<c; j++)
            mtx[i][j] = (random()%MAX);
    }
}
void showMtx(int mtx[][MAX], int r, int c){
    for(int i=0; i<r; i++){ 
        for (int j=0; j<c; j++)
            cout << left << setw(6) << mtx[i][j];
        cout << endl;
    }
}
void showMtx2(int mtx[][MAX], int r, int c){
    for(int i=0; i<r; i++){
        for (int j=0; j<c; j++)
            cout << left << (j==0?setw(6):setw(8)) << mtx[i][j];
        cout << endl;
    }
}

void multiply(int mtx1[][MAX], int mtx2[][MAX], int mtx3[][MAX], int r, int m, int c){
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            mtx3[i][j] =0;
            for(int k=0; k<m; k++)
                mtx3[i][j] += (mtx1[i][k])*(mtx2[k][j]);
        }
    }
}

