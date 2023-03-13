#include <iostream> 
#include <iomanip> 
#include <cstdlib> 
using namespace std; 
 
const int MAXSIZE=10; 
int numrow,numcol1,numcol2; 
 
void showMatrix(int , int, int [][MAXSIZE]); 
void random(int, int, int [][MAXSIZE]); 
void mul (int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE]); 
 
int main(){ 
        srand(2001);     
        cout << "Please enter rows and cols of 1st matrix: "; 
        cin>>numrow>>numcol1; 
        cout << "Please enter cols of 2nd matrix: "; 
        cin>>numcol2; 
        int matrix1[MAXSIZE][MAXSIZE],matrix2[MAXSIZE][ MAXSIZE]; 
        random(numrow,numcol1,matrix1); 
        random(numcol1,numcol2,matrix2); 
        cout << "Matrix1" << endl; 
        showMatrix (numrow,numcol1,matrix1); 
        cout << "Matrix2" << endl; 
        showMatrix (numcol1,numcol2,matrix2); 
        int matrix3[MAXSIZE][MAXSIZE]={0}; 
        mul(matrix1,matrix2,matrix3); 
        cout << "Matrix3" << endl; 
        showMatrix (numrow,numcol2,matrix3); 
 
        return 0; 
}
void showMatrix(int a, int b, int c[][MAXSIZE]){
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++){
                if (j!=b-1)
                    cout<<left<<setw(8)<<c[i][j];
                else 
                    cout<<c[i][j]<<endl;
            }
        }
    return ;
} 
void random(int a, int b, int c[][MAXSIZE]){ 
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++)
                c[i][j]=rand()%100;
    return ;
}
void mul (int a[][MAXSIZE], int b[][MAXSIZE], int c[][MAXSIZE]){
    for (int i=0;i<numcol2;i++)
        for (int j=0;j<numrow;j++){
            int sum=0;
            for(int k=0;k<numcol1;k++)
                sum+=a[j][k]*b[k][i];
            c[j][i]=sum;
        }
    return;
}
