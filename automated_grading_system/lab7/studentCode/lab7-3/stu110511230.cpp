#include<iostream>
#include<iomanip>
using namespace std;

int ro1,cl1,cl2;
int m1[10][10];
int m2[10][10];
int m3[10][10];

int main (){
	srand(2001);
	cout << "Please enter rows and cols of 1st matrix: ";
	cin >> ro1 >> cl1;
	cout << "Please enter cols of 2nd matrix: ";
	cin >> cl2;
	cout << "Matrix1" << endl;
	for(int i = 0;i<ro1;i++){
		for(int j = 0;j<cl1;j++){
			m1[i][j]=(rand()%100);
			cout << left << setw(8) << m1[i][j];
		}
		cout << endl;
	}
	cout << "Matrix2"<< endl;
	for(int i = 0;i<cl1;i++){
		for(int j = 0;j<cl2;j++){
			m2[i][j]=(rand()%100);
			cout << left << setw(8) << m2[i][j];
		}
		cout << endl;
	}
	cout << "Matrix3"<< endl;
	for(int i = 0;i < ro1;i++){
		for(int j = 0;j<cl2;j++){
			for (int k=0;k<cl1;k++){
				m3[i][j]+=(m1[i][k]*m2[k][j]);
			}
			cout << left << setw(8) << m3[i][j];
		}
		cout << endl;
	}
}
