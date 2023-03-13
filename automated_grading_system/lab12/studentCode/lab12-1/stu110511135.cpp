#include<iostream>
#include<iomanip>

using namespace std;
void sortarr(int*, int*,int, int, int, int&, int&);
int main(){
    int n,count=0;  
    cin >> n;
while(n!=-1){
    int *vec = new int[n*n];
    int *arr = new int[n*n];
    for(int i=0; i<(n*n+1)/2; i++){
        vec[i] = i*2+1;
        arr[i] = i*2+1;
    }
    int a=1;
    for(int i=(n*n+1)/2; i<n*n; i++){
        vec[i] = 2*a;
        arr[i] = 2*a;
        a++;
    }
    int start = -1; 
    int idx = 0;
    sortarr(vec, arr, n, count, n, start, idx);
    count++;
    for(int i=n-1; i>0; i--){
        sortarr(vec, arr, n, count, i, start, idx);
        count++;
        sortarr(vec, arr, n, count, i, start, idx);
        count++;
    }
    for(int i=0; i<n*n; i++){
        cout << right << setw(5) << vec[i];
        if(i%n==n-1){cout << endl;}
    }
    cin >> n;
    delete []vec; delete []arr;
    //start=-1; idx=0; count=0; a=1;
    count=0;
    vec = new int[n*n];
    arr = new int[n*n];
}
return 0;
}

void sortarr(int vec[],int arr[], int n, int count, int num, int &start, int &idx){
    if(count%4==0){
        for(int i=0; i<num; i++){
            start++;
            vec[start] = arr[idx];
            idx++;
        }
    }if(count%4==1){
        for(int i=0; i<num; i++){
            start+=n;
            vec[start] = arr[idx];
            idx++;
        }
    }if(count%4==2){
        for(int i=0; i<num; i++){
            start--;
            vec[start] = arr[idx];
            idx++;
        }
    }if(count%4==3){
        for(int i=0; i<num; i++){
            start -= n;
            vec[start] = arr[idx];
            idx++;
        }
    }
}
