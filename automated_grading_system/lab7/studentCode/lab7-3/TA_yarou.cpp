#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){

    srand(2001);
    cout << "Please enter rows and cols of 1st matrix: ";
    int r1, c1, c2;
    int w = 8;
    cin >> r1 >> c1;
    cout << "Please enter cols of 2nd  matrix: ";
    cin >> c2;
    int m1[r1][c1], m2[c1][c2];

    cout << "Matrix1" << endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            m1[i][j] = rand()%100;
            cout<< left<<setw(w)<<m1[i][j];
        }     
        cout << endl;
    }
    cout << "Matrix2" << endl;
    for(int i=0; i<c1; i++){
        for(int j=0; j<c2; j++){
            m2[i][j] = rand()%100;
            cout<< left<<setw(w)<<m2[i][j];
        }     
        cout << endl;
    }

    cout << "Matrix3" << endl;

    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            int total = 0;
            for(int k=0; k <c1; k++){
                total += m1[i][k]*m2[k][j];
            }
            cout <<left<<setw(w)<<total;
        }     
        cout << endl;
    }
    
}
