#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXSIZE=10;
int numrow,numcol1,numcol2;

void showMatrix(int, int, int [][MAXSIZE]);
void random(int, int, int [][MAXSIZE]);
void mul(int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE]);

int main(){
	srand(2001);
	cout << "Please enter rows and cols of 1st matrix: " ;
	cin >> numrow >> numcol1;
	cout << "Please enter cols of 2nd matrix: ";
	cin >> numcol2;

	int maxtrix1[MAXSIZE][MAXSIZE], maxtrix2[MAXSIZE][MAXSIZE];
	random(numrow,numcol1,maxtrix1);
	random(numcol1,numcol2,maxtrix2);
	cout << "Matrix1" << endl;
	showMatrix(numrow,numcol1,maxtrix1);
	cout << "Matrix2" << endl;
	showMatrix(numcol1,numcol2,maxtrix2);

	int maxtrix3[MAXSIZE][MAXSIZE]={0};
	mul(maxtrix1,maxtrix2,maxtrix3);
	cout << "Matrix3" << endl;
	showMatrix(numrow,numcol2,maxtrix3);

	return 0;
}

void random(int r,int c,int M[][MAXSIZE]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			M[i][j] = rand()%100;
		}
	}
}
void showMatrix(int r,int c,int Matrix[][MAXSIZE]){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout <<setw(8) << left << Matrix[i][j];
		}	
		cout << endl;	
	}
}

void mul(int m1[][MAXSIZE], int m2[][MAXSIZE], int m3[][MAXSIZE]){

	for(int i=0;i<MAXSIZE;i++){
                for(int j=0; j<MAXSIZE;j++){
                        for (int k=0;k<MAXSIZE;k++){
                        m3[i][j] += m1[i][k]*m2[k][j];
                        }

                }
        }
}
