#include <iostream>
#include <iomanip>
using namespace std;

int **CreateArray(int);
void PrintArray(int**,int);
void Delete(int**,int);
int main(){

	int n=0;
	cin >> n;
	while(n!=-1){
		int **array = CreateArray(n);
		PrintArray(array,n);
		Delete(array,n);
		cin >> n;
	}
	return 0;
}

int **CreateArray(int n){
	int **vec = new int*[n];
	for(int i=0;i<n;i++){
		vec[i] = new int [n];
	}
	return vec;
}
void PrintArray(int **a, int n){
	int j,k = 1;
	int odd = ((n*n)%2==1)?(n*n/2+1):(n*n/2);
	for(int i=0; i<=n/2; i++){
		for(j=i;j<n-i;j++){
			a[i][j] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
		for(j=i+1;j<n-i;j++){
			a[j][n-i-1] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
		for(j=n-i-2;j>i;j--){
			a[n-1-i][j] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
		for(j=n-i-1;j>i;j--){
			a[j][i] = (k>odd)?(2*(k-odd)):(2*k-1);
			k++;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << fixed << setw(5) << right << a[i][j];
		}
		cout << endl;
	}
}
void Delete(int **mat, int n){
	for(int i=0;i<n;i++){
		delete [] mat[i];
	}
	delete []mat;
}
