#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main () {
    while(1) {
        int size;
        cin >> size;
        if(size==-1)
            break;
        int **vec = new int *[size];
        for(int i=0;i<size;i++) {
            vec[i] = new int[size];
        }
        //vec={0};
        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                vec[i][j]=0;
            }
        }
        int i=0,j=0,k=1,m=0;
        while(k<=pow(size,2)+3) {
           // if(k==pow(size,2)-1)
             //   k=2;
            if(size%2==0&&k==pow(size,2)+1) {
                        k=2;
                       // cout << 123 << endl;
            }
            if(size%2==1&&k==pow(size,2)+2) {
                        k=2;
                        //cout << 123 << endl;
            }
            if(size%2==0&&k==pow(size,2)) {
                vec[i][j]=k;
                k+=2;
                break;;
            }
            if(size%2==1&&k==pow(size,2)-1) {
                vec[i][j]=k;
                k+=2;
                break;
            }
            if(i==0&&j!=size-1) {
                if(vec[i][j+1]==0) {
                    vec[i][j]=k;
                    j++,k+=2;
                    continue;
                }
            }
            if (j!=size-1) {
                if(vec[i][j+1]==0&&vec[i-1][j]!=0) {
                    vec[i][j]=k;
                    j++,k+=2;
                    /*if(size%2==0&&k==pow(size,2)-1)
                        k=2;
                    if(size%2==1&&k==pow(size,2))
                        k=2;*/
                    continue;
                }
            }
            if(i!=size-1) {
                if(vec[i+1][j]==0) {
                    vec[i][j]=k;
                    i++,k+=2;
                    /*if(size%2==0&&k==pow(size,2)-1)
                        k=2;
                    if(size%2==1&&k==pow(size,2))
                        k=2;*/
                    continue;
                }
            }
            if(j!=0) {
                if(vec[i][j-1]==0) {
                    vec[i][j]=k;
                    j--,k+=2;
                    /*if(size%2==0&&k==pow(size,2)-1)
                        k=2;
                    if(size%2==1&&k==pow(size,2))
                        k=2;*/
                    continue;
                }
            }
            if(vec[i-1][j]==0){
                vec[i][j]=k;
                i--,k+=2;
                /*if(size%2==0&&k==pow(size,2)-1)
                    k=2;
                if(size%2==1&&k==pow(size,2))
                        k=2;*/
                continue;
            }
            /*if(k==pow(size,2)) {
                vec[i][j]=k;
                k+=2;
            }
            if(k==pow(size,2)-1) {
                k==2;
            }*/
        }
        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                cout << setw(5) << right << vec[i][j];
                if(j==size-1)
                    cout << endl;
            }
        }
    }
    return 0;
}
