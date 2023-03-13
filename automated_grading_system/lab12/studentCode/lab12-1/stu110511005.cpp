#include<iostream>
using namespace std;
#include<iomanip>

int main() {
    int n;
    cin >> n;
    while (n!=-1) {
        int count = 1;
        int noo = (n*n+1)/2;
        int **mtx;
        mtx = new int *[n];
        for (int k=0 ; k<n ; k++) {
            mtx[k] = new int [n];
        }
        for(int j=0 ; j<(n+1)/2 ; j++) {
		    for(int k=0;k<n-j*2-1;k++) {  
		    	mtx[j][k+j] = count++;
		    }
		    for(int k=0;k<n-j*2-1;k++) {
		        mtx[k+j][n-j-1] = count++;
		    }
		    for(int k=0;k<n-j*2-1;k++) { 
		        mtx[n-j-1][n-j-k-1] = count++;
		    }
		    for(int k=0;k<n-j*2-1;k++) {
			    mtx[n-j-k-1][j] = count++;
		    }
        }
        if(n%2) {
			mtx[n/2][n/2]=count++;
	    }

        for(int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (mtx[i][j] <= noo) { //output odd
                    mtx[i][j] = 2*mtx[i][j]-1;
                }
                else { //ouput even
                    mtx[i][j] = (mtx[i][j] - noo)*2; 
                }
            }
        }
    
        for(int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                cout << setw(5) << right << mtx[i][j];
            }  
            cout << endl; 
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
