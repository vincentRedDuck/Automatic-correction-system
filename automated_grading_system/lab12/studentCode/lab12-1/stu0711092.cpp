#include<iostream>
#include<iomanip>
using namespace std;


int **NEW(int);
void print(int);

int main(){

	int n;  cin >> n;
	while(n != -1){	
	int **mat = NEW(n);
	print(n);
	cin >> n;
	}
}

int **NEW(int n){

	int **mat = new int*[n];
	for(int i=0;i<n;i++){
		mat[i] = new int[n];
	}
	return mat ;
}

void print(int n){

	int *a = new int [n] ;
	int j,k = 1;
	int odd = (n*n)%2==1?(n*n/2+1):(n*n/2);

	int ct = 0;
	int **mat = NEW(n);

	for(int i = 0;i<=n/2;i++){
		for(int j= i;j<n-i;j++) {
			mat[i][j] =(k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		};
		for(int j=i+1;j<n-i;j++){ 
			mat[j][n-i-1]= (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
		for(int j= n-i-2;j>i;j--) {
			mat[n-i-1][j] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
		for(int j = n-i-1;j>i;j--){ mat[j][i] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++) cout << setw(5) << mat[i][j] ;
		cout << endl;
	}

}
