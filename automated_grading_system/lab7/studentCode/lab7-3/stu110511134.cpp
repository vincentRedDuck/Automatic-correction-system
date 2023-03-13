#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXSIZE=10;

int numrow,numcol1,numcol2;

void initMatrix(int , int, int [][MAXSIZE]);
void showMatrix(int, int, const int [][MAXSIZE]);

void mul(int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE],int,int,int);

int main(){
	srand(2001);
	int matrix1[MAXSIZE][MAXSIZE],matrix2[MAXSIZE][MAXSIZE],matrix3[MAXSIZE][MAXSIZE]={0};
	
	//int x,y,z;int numrow,numcol1,numcol2;
	
	cout << "Please enter rows and cols of 1st matrix: ";
	cin>>numrow>>numcol1;
	
	cout << "Please enter cols of 2nd matrix: ";
	cin>>numcol2;
	
	
	
	initMatrix(numrow,numcol1,matrix1);
	initMatrix(numcol1,numcol2,matrix2);    //col1 is euqal to row2;

	cout << "Matrix1" << endl;
	showMatrix (numrow,numcol1,matrix1);
	cout << "Matrix2" << endl;
	showMatrix (numcol1,numcol2,matrix2);
 
	//int matrix3[MAXSIZE][MAXSIZE]={0};
	
 	mul(matrix1,matrix2,matrix3,numrow,numcol1,numcol2);
 	cout << "Matrix3" << endl;
 	showMatrix (numrow,numcol2,matrix3);
 	return 0;
}
void initMatrix(int r, int c, int mtx[][MAXSIZE]){	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			mtx[i][j] = (random()%100/*MAXSIZE*/);
		}
	}
}

void showMatrix(int r, int c,const int mtx[][MAXSIZE]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << setw(8) << left << mtx[i][j];
		}
		cout << endl;
	}
}

void mul (int a[][MAXSIZE], int b[][MAXSIZE], int c[][MAXSIZE],int p,int q,int r){
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			c[i][j] = 0;
			for(int k=0;k<q;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
	
	/*for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cout << setw(4) << left << c[i][j];
		}
		cout << endl;
	}*/
}


