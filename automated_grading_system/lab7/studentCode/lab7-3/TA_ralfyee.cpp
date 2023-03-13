#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXSIZE=10;
int numrow,numcol1, numcol2;

void initMatrix(int [][MAXSIZE]);
void showMatrix(int , int, int [][MAXSIZE]);
void random(int, int, int [][MAXSIZE]);
void mul (int [][MAXSIZE], int [][MAXSIZE], int [][MAXSIZE]);

int main()
{
    	srand(2001);  
    	cout << "Please enter rows and cols of 1st matrix: ";
	    cin>>numrow>>numcol1;
	    cout << "Please enter cols of 2nd matrix: ";
	    cin>>numcol2;
    	int matrix1[MAXSIZE][MAXSIZE],matrix2[MAXSIZE][MAXSIZE];
      initMatrix(matrix1);
      initMatrix(matrix2);
	    random(numrow,numcol1,matrix1);
	    random(numcol1,numcol2,matrix2);
    	cout << "Matrix1" << endl;
   	  showMatrix(numrow,numcol1,matrix1);
    	cout << "Matrix2" << endl;
    	showMatrix(numcol1,numcol2,matrix2);
    	
	    int matrix3[MAXSIZE][MAXSIZE]={0};
    	mul(matrix1,matrix2,matrix3);
    	cout << "Matrix3" << endl;
    	showMatrix(numrow,numcol2,matrix3);

    return 0;
}

void showMatrix(int rowSize, int columnSize, int matrix[][MAXSIZE])
{
    for(int i =0; i<rowSize; i++)
    {
        for(int j=0; j<columnSize; j++)
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
    }
}

void random(int rowSize, int columnSize, int matrix[][MAXSIZE])
{
    for(int i =0; i<rowSize; i++)
        for(int j=0; j<columnSize; j++)
            matrix[i][j] = rand()%100;
}

void initMatrix(int matrix[][MAXSIZE])
{
    for(int i =0; i<MAXSIZE; i++)
        for(int j=0; j<MAXSIZE; j++)
            matrix[i][j] = 0;
}
void mul (int matrix1[][MAXSIZE], int matrix2[][MAXSIZE], int matrix3[][MAXSIZE])
{
    for(int i = 0; i < numrow; ++i)
        for(int j = 0; j < numcol2; ++j)
            for(int k = 0; k < numcol1; ++k)
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
}
