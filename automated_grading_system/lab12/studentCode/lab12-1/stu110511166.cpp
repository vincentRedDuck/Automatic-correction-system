#include<iostream>
#include<iomanip>
using namespace std;
bool updown(int);
int main(){
    int a;
    cin >> a;
    while(a != -1){
        //int arr[a][a];
        int **arr;
        arr = new int *[a];
        for(int i = 0; i < a; i++){
            arr[i] = new int [a];
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                arr[i][j] = 0;
            }
        }
        int count = 1;
        int x = 0;
        int i = a;
        int row = 0;
        int col = 0;
        while(i != 0){
            if(i == a){
                for(int j = 0; j < i; j++){
                    arr[row][col] = count;
                    count += 2;
                    if(j != i-1)
                        col++; 
                }   
                x++;
            }
            else{
                row += (updown(x))?1:-1;
                for(int j = 0; j < i; j++){
                    if(count > a*a && count%2 == 1)
                        count = 2;
                    //int p = (updown(x))?1:-1;
                    arr[row][col] = count;
                    count += 2;
                    if(j != i-1)
                        (updown(x))?row++:row--;
                    //cout << updown(i,a) << " ";
                }
                x++;
                col += (updown(x))?1:-1;
                for(int j = 0; j < i; j++){
                    if(count > a*a && count%2 == 1)
                        count = 2;
                    arr[row][col] = count;
                    count += 2;
                    if(j != i-1)
                        (updown(x))?col++:col--;
                    //cout << updown(i,a) << " ";
                }
                x++;
            }
            i--;
            //x++;
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++)
                cout << setw(5) << arr[i][j];
            cout << endl;
        }
            
        cout << endl;
        cin >> a;
    }
    return 0;
}

bool updown(int x){
    bool flag = true;
    if(x%4==2||x%4==3)
        flag = false;
    return flag;
}
