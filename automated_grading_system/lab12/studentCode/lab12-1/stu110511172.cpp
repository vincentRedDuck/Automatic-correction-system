#include <iostream>
#include<iomanip>
using namespace std;
int **New2DArray(int);
void Initial2DArray(int **,int);
void Display2DArray(int **,int);
void Delete2DArray(int **,int);
int main()
{
    int m=0;
    while(m!=-1){
        cin >> m;
        if(m!=-1){
        int **vec = New2DArray(m);
        Initial2DArray(vec,m);
        Display2DArray(vec,m);
        Delete2DArray(vec,m);}
    }
return 0;
}

int **New2DArray(int m)
{
    int **mat = new int *[m];
    for (int idx = 0;idx < m; idx++)
    mat[idx] = new int [m];
    return mat;
}


void Initial2DArray(int **mat, int m)
{
int i=0;
int j=0;
int num=1;
int t = 1;
for(int idx=0;idx<m;idx++){
    for(int jdx = 0; jdx < m;jdx++)
        mat[idx][jdx] = 0;
}

for (int mdx = m;mdx > 0; mdx--){
    if(mdx == m){
        for (int idx = 0; idx < mdx ;idx++){
            mat[i][j] = num;
            num += 2;
            j++;
        }
        j--;
    }
    else{
        for (int idx = 0; idx < mdx; idx++){
            if (t == -1)
                i--;
            if (t == 1)
                i++;
            if (num > m*m)
                num = 2;
            mat[i][j] = num;
            num += 2;
        }
        t = -t;
        for (int jdx = 0; jdx < mdx; jdx++){
            if (t == -1)
                j--;
            if (t == 1)
                j++;
            if (num > m*m)
                num = 2;
            mat[i][j] = num;
            num += 2;
        }
    }
}

}

void Display2DArray(int **mat, int m)
{
for (int idx = 0;idx < m; idx++)
{
    for (int jdx = 0;jdx < m; jdx++)
    cout << setw(5) << right << mat[idx][jdx];
    cout << endl;
}
}

void Delete2DArray(int **mat,int m)
{ 
for (int idx = 0; idx < m; idx++)
delete [] mat[idx];
delete [] mat;
}

