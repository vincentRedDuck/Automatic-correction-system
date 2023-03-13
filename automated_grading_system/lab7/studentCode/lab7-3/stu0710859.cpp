#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    srand(2001);
    int m, n, x;
    int i, j, k;
    cout << "Please enter rows and cols of 1st matrix: ";
    cin >> m >> n;
    cout << "Please enter cols of 2nd matrix: ";
    cin >> x;
    int mat1[10][10], mat2[10][10], mat3[10][10]={0};
    cout << "Matrix1" << endl;
    for(i = 0; i < m; i++){
        for( j = 0; j < n; j++){
            mat1[i][j] = rand()%100;
            cout << std::left << setw(7)<< mat1[i][j];
        }
        cout <<endl;
    }
    cout << "Matrix2" << endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < x; j++){
            mat2[i][j] = rand()%100;
            cout<< std::left << setw(7) << mat2[i][j];
        }
        cout <<endl;
    }
    cout << "Matrix3" << endl;
    for(i = 0; i < m; i++){
        for(j = 0; j < x; j++){
            for(k = 0; k < n; k++){
                mat3[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    for(i = 0; i < m; i++){
        for( j = 0; j < x; j++){
            cout << std::left << setw(7) << mat3[i][j];
            if(j != x-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
