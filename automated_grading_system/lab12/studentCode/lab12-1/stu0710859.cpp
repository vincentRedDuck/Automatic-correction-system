#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, i, j, sum, cur;
    int left, right, top, bot;
    cin >> n;
    while(n != -1){
        left = 0;
        right = n-1;
        top = 0;
        bot = n-1;
        cur = 1;
        int **arr = new int*[n];
        for(i = 0; i < n; i++){
            arr[i] = new int[n];
        }
        sum = n*n;
        while(1){
            if(left > right)
                break;
            for(i = left; i <= right; i++){
                arr[top][i] = cur;
                cur += 2;
                if(cur > sum){
                    cur = 2;
                }
            }
            top++;
            if(top > bot)
                break;
            for(i = top; i <= bot; i++){
                arr[i][right] = cur;
                cur += 2;
                if(cur > sum){
                    cur = 2;
                }
            }
            right--;
            if(left > right)
                break;
            for(i = right; i >= left; i--){
                arr[bot][i] = cur;
                cur += 2;
                if(cur > sum){
                    cur = 2;
                }
            }
            bot--;
            if(top > bot)
                break;
            for(i = bot; i >= top; i--){
                arr[i][left] = cur;
                cur += 2;
                if(cur > sum){
                    cur = 2;
                }
            }
            left++;
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                cout << setw(5) << arr[i][j];
            }
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}
