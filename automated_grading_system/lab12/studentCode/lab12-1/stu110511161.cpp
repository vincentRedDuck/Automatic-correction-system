#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    while(1){
        int n=0, ans=1; cin >> n;
        if(n==-1)break;
        
        int **mtx = new int *[n];
        for(int i=0; i<n; i++)mtx[i] = new int [n];

    if(n==1)mtx[0][0]=1;
    else{
        for(int i=0; i<(n+1)/2; i++){
            const int last = n-i-1;
            if(i == last)mtx[n/2][n/2] = (n*n)-1;
            else{
                for(int j=i; j<last; j++){
                    mtx[i][j] = ans;
                    ans += 2; if(ans > n*n)ans=2;
                }
                for(int j=i; j<last; j++){
                    mtx[j][last] = ans;
                    ans += 2; if(ans > n*n)ans=2;
                }
                for(int j=last; j>i; j--){
                    mtx[last][j] = ans;
                    ans += 2; if(ans > n*n)ans=2;
                }
                for(int j=last; j>i; j--){
                    mtx[j][i] = ans;
                    ans += 2; if(ans > n*n)ans=2;
                }
            }
        }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << setw(5) << right << mtx[i][j];
            }
            cout << endl;
        }

        for(int i=0; i<n; i++)delete [] mtx[i];
        delete [] mtx;
        mtx = NULL;
    }
    return 0;
}
