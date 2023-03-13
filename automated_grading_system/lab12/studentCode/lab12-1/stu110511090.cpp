#include <iostream>
#include <iomanip>
using namespace std;
    
int **New2DArray(const int);
void Initial2DArray(int **, const int, int *);
void Display2DArray(int **, const int);
void Delete2DArray(int **, const int);

int main(){
    int x;
    cin >> x;
    while(x != -1){
        int **vec = New2DArray(x);
        int arr[x*x+1];
        int n = 0;
        for(int i = 1; i <= x*x; i = i+2){
            arr[n++] = i;
        }
        for(int i = 2; i <= x*x; i = i+2){
            arr[n++] = i;
        }
        //for(int i = 0; i < n; i++)
            //cout << arr[i];
        Initial2DArray(vec,x,arr);
        Display2DArray(vec,x);
        Delete2DArray(vec,x);
        cin >> x;
    }
    return 0;
}

int **New2DArray(const int x){
    int **mat = new int *[x];
    for (int idx = 0; idx < x; idx++)
        mat[idx] = new int [x];
    return mat;
}
void Initial2DArray(int **mat, const int x, int *arr){
    int left = 0, right = x-1, top = 0, bottom = x-1, n = 0;
    while(n < x*x){
        for(int i = left; i <= right; i++){
            mat[top][i] = arr[n++];
        }
        top++;
        for(int i = top; i <= bottom; i++){
            mat[i][right] = arr[n++];   
        }
        right--;
        for(int i = right; i >= left; i--){
            mat[bottom][i] = arr[n++];
        }
        bottom--;
        for(int i = bottom; i >= top; i--){
            mat[i][left] = arr[n++];
        }
        left++;
    }
}
void Display2DArray(int **mat, const int x){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cout << setw(5) << right << mat[i][j];
        }
        cout << endl;
    }
}
void Delete2DArray(int **mat, const int x){
    for(int i = 0; i<x; i++){
        delete [] mat[i];
    }
    delete []mat;
}
