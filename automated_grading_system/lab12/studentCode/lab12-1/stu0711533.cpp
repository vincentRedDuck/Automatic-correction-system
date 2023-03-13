#include <iostream>
#include <iomanip>
using namespace std;
int **newArray(const int);
void initialArray(int **, const int);
void displayArray(int **, const int);
void deleteArray(int **, const int);

int main() {
	int num;
 	while((cin >> num) && (num != -1)) {
 		int **mtx = newArray(num);
 		initialArray(mtx, num);
 		displayArray(mtx, num);
// 		deleteArray(mtx, num);
 	}
	return 0;
}

int **newArray(const int n) {
	int **mtx = new int *[n];
 	for(int row=0; row<n; row++)
 		mtx[row] = new int [n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            mtx[i][j] = 0;
    }
 	return mtx;
}

void initialArray(int **mtx, const int n) {
	int dir_x[4] = {0, 1, 0, -1}; int dir_y[4] = {1, 0, -1, 0};
	int index = 0, x = 0, y = -1, temp_x, temp_y;
	int odd = 1; int even = 2;
	for(int i=0; i<n*n; i++) {
		temp_x = x + dir_x[index]; temp_y = y + dir_y[index];
		if(temp_x<0 || temp_x>n-1 || temp_y<0 || temp_y>n-1 || mtx[temp_x][temp_y]!=0) index = (index + 1) % 4;

		x = x + dir_x[index]; y= y + dir_y[index];
		if(odd <= n*n){
			mtx[x][y] = odd;
			odd += 2;
		}
		else if(even <= n*n) {
			mtx[x][y] = even;
			even += 2;			
		}

	}
}

void displayArray(int **mtx, const int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) 
			cout << setw(5) << right << mtx[i][j]; 
		cout << endl;
	}
}

void deleteArray(int **mtx, const int n) {
	for(int i=0; i<n; i++) 
		delete [] mtx[n];
	delete [] mtx;
}
