#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != -1){
        int **arr = new int* [n];
        for(int i=0; i<n; ++i)
            arr[i] = new int[n];

        for(int i=0, r=0, c=-1, tok=n, cnt=0; i<n*n; ++cnt){
            for(int j=0; j<tok; ++j){
                int out = (i>(n*n-1)/2? 2*(i-(n*n-1)/2): 2*i+1);
                if(cnt%2 == 0){
                    c += (int)pow(-1, cnt/2);
                    arr[r][c] = out;
                    //cout << cnt << tok << r << c << " ";
                }

                else{
                    r += (int)pow(-1, cnt/2);
                    arr[r][c] = out;
                    //cout << cnt << tok << r << c << " ";
                }

                ++i;
            }

            if(cnt%2 == 0)
                --tok;
        }
        

        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cout << right << setw(5) << arr[i][j] << (j==n-1? "\n": "");
        //cout << "\n";

        cin >> n;
    }


}

