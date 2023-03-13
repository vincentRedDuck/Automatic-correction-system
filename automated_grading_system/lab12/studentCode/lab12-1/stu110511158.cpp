#include<iostream>
#include<iomanip>

using namespace std;

int **Array(const int);
void InitialArray(int **,const int);
void displayarray(int **,const int);
void deletearray(int **,const int);
int main() {
    int n;
    while (cin >> n) {
        if (n==-1)
            break;
        int **vec = Array(n);
        int count =1;
        int i =0;
        int m = n;
        bool flag = false;
        while (n>i) {
            //cout << n << " " << i << endl;
            for (int jdx = i; jdx < n-1 ;jdx++) {
                vec[i][jdx] = count;
                count +=2;
                if (count >m*m && count%2==1)
                    count =2;
                else if (count >m*m && count %2==0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            for (int jdx = i;jdx < n-1;jdx ++) {
                vec[jdx][n-1] = count;
                count +=2;
                if (count >m*m && count%2==1)
                    count =2;
                else if (count >m*m && count %2==0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            for (int jdx = n-1;jdx >i;jdx--) {
                vec[n-1][jdx] = count;
                count +=2;
                if (count >m*m && count%2==1)
                    count =2;
                else if (count >m*m && count %2==0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            for (int jdx = n-1;jdx >i;jdx--) {
                vec[jdx][i] = count;
                count +=2;
                if (count >m*m && count%2==1)
                    count =2;
                else if (count >m*m && count %2==0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            n--;
            i++;
        }
        if(m%2==1)
        vec[(m)/2][(m)/2]=m*m-1;        
        displayarray(vec,m);
        deletearray(vec,m);
    }
    return 0;
}

int **Array(const int m)
{
    int **mat = new int *[m];
    for (int idx = 0;idx< m;idx++) {
        mat[idx] = new int[m];
        //cout << endl;
    }
    return mat;
}

void displayarray(int **mat,const int m) 
{
    for (int idx=0;idx<m;idx++) {
        for (int jdx=0;jdx<m;jdx++) 
            cout << setw(5) << right << mat[idx][jdx] ;
        cout << endl;
    }    
}
void deletearray(int **mat,const int m)
{
    for (int idx = 0;idx <m;idx++)
        delete [] mat[idx];
    delete []mat; 
}
