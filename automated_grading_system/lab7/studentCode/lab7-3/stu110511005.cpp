/*#include<iostream>
using namespace std;
#include<ctime>
#include<cmath>
#include<iomanip>
#include<vector>

int main() {
    cout << "Please enter rows and cols of lst matrix: ";
    int r1,c1;
    cin >> r1 >> c1;
    cout << "Please enter cols of 2nd matrix: ";
    int c2;
    cin >> c2;
    srand(time(NULL));

    vector<vector<int>> mat1(r1); //vector<元素型態>
    for (int i=0 ; i<r1 ; i++) {
        mat1[i].resize(c1);
    }
    for (int i=0 ; i<r1 ; i++) {
        for (int j=0 ; j<c1 ; j++) {
            mat1[i][j] = rand()%100;
        }   
    }
    cout << "Matrix1" << endl;
    for (int i=0 ; i<r1 ; i++) {
        for (int j=0 ; j<c1 ; j++) {
            cout << setw(8) << left << mat1[i][j];
        }
        cout << endl;
    }
    
    vector<vector<int>> mat2(c1);
    for (int i=0 ; i<c1 ; i++) {
        mat2[i].resize(c2);
    }    
    for (int i=0 ; i<c1 ; i++) {
        for (int j=0 ; j<c2 ; j++) {
            mat2[i][j] = rand()%100;
        }
    }   
    cout << "Matrix2" << endl;
        for (int i=0 ; i<c1 ; i++) {
            for (int j=0 ; j<c2 ; j++) {
                cout << setw(8) << left << mat2[i][j];
            }
            cout << endl;
        }

    vector<vector<int>> mat3(r1);
    for (int i=0 ; i<r1 ; i++) {
        mat3[i].resize(c2);
    }
    for (int i=0 ; i<r1 ; i++) {
        for (int j=0 ; j<c2 ; j++) { //each element
            for (int k =0 ; k<c1 ; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "Matrix3" << endl;
    for (int i=0 ; i<r1 ; i++) {
        for (int j=0 ; j<c2 ; j++) {
            cout << setw(8) << left << mat3[i][j];
        }
        cout << endl;
    }
    return 0;
}*/


#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	srand(2001);

	cout << "Please enter rows and cols of 1st matrix: ";
	

	int row1, col1;
	cin >> row1 >> col1;
	

	cout << "Please enter cols of 2nd matrix: ";
	

	int col2;
	cin >> col2;
	
	vector<vector<int>> mat1(row1);
	for (int i = 0; i < row1; i++) {
		mat1[i].resize(col1);
		
	}
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			mat1[i][j] = rand() % 100;
		}
	}
	
	vector<vector<int>> mat2(col1);
	for (int i = 0; i < col1; i++) {
		mat2[i].resize(col2);
		for (int j = 0; j < col2; j++) {
			mat2[i][j] = rand() % 100;
		}
	}

	cout << "Matrix1" << endl;

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			cout << setw(8) << left << mat1[i][j];
		}
		cout << endl;
	}

	cout << "Matrix2" << endl;

	for (int i = 0; i < col1; i++) {
		for (int j = 0; j < col2; j++) {
			cout << setw(8) << left << mat2[i][j];
		}
		cout << endl;
	}

	vector<vector<long long>> res(row1);
	for (int i = 0; i < row1; i++) {
		res[i].resize(col2);
	}

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			// for every element in res
			for (int k = 0; k < col1; k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	cout << "Matrix3" << endl;

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			cout << setw(8) << left << res[i][j];
		}
		cout << endl;
	}

	return 0;
}
