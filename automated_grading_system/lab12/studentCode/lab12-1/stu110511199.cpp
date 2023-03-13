#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void fillMtx(int **, int );
void prtMtx(int **, int );

int main () {
    int size;
    cin >> size;
    while (size!=-1){ 
        if (size==1) {
            cout << right << setw(5) << 1 << endl;
        }
        else{
            int **mtx = new int *[size];
            for (int r=0; r < size; r++) {
                mtx[r] = new int [size];
            }
            //cerr<<"wwwwwwwwwwwwwwwwwwwwwwwwwww";
            fillMtx(mtx, size);
            prtMtx(mtx, size);
            for (int r=0; r < size; r++) {
                delete [] mtx[r];
            }
            delete [] mtx;
        }
        cin >> size;
    }
    return 0;
}

void fillMtx(int **arr, int n) {
    int num = 0, t = 1, l=0;
    int r = 0, c = 0;
    int s = n-1;
    for (int i=0; i<(n*n); i++){
        num = 2*i+1;
        if (num > (n*n)) {
            num = 2*t;
            t++;
        }
        arr[r][c] = num;
       
        if (((i-l)/s)%4==0) c++;
        else if (((i-l)/s)%4==1) r++;
        else if (((i-l)/s)%4==2) c--;
        if (((i-l)/s)%4==3){
            if (((i+1-l)/s)%4==0) {
                l+=4*s;
                s-=2;
                if (s==0) s=1;
                c++;
            } else r--;
        }
    }
    
}
void prtMtx(int **arr, int n) {
    for (int r=0; r<n; r++){
        for (int c=0; c<n; c++){
        cout << right << setw(5) << arr[r][c] ;
        }
        cout << endl;
    }
}
