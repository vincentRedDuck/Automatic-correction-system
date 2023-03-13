#include <iostream>
#include <iomanip>
#include <cmath>
//#include <iostream>

using namespace std;

int **New2DArray(const int,const int);
void Initial2DArray(int **,const int,const int);
void Display2DArray(int **,const int,const int);
void Delete2DArray(int **,const int);

int main(){

    while(1){


        int m,n;
        //cout << "Enter the size of array: " << endl;
        cin >> m;

        n=m;

        if(n == -1){
            break;
        }
        else{

            int **vec = New2DArray(m,n);
            Initial2DArray(vec,m,n);
            Display2DArray(vec,m,n);
            Delete2DArray(vec,m);

        }


    }

    return 0;
}

int **New2DArray(const int m, const int n){
 int **mat = new int *[m];
 for (int idx = 0;idx < m; idx++)
 mat[idx] = new int [n];
 return mat;
}

void Initial2DArray(int **mat, const int m, const int n){
    for (int idx = 0;idx < m;idx++){
        for (int jdx = 0; jdx < n; jdx++)
        mat[idx][jdx] = 0;
    }

    int x=0,y=-1;
    int step=m-1;
    int state = 0;//順時針 M=1 0右 1下 2左 3上
    int k =0;
    int odd=0;
    if(m%2==1)odd=1;
    else odd=0;

    for(int j=0;j<m;j++){
        k++;
        if(state==0)y++;
        else if(state==1)x++;
        else if(state==2)y--;
        else if(state==3)x--;

        mat[x][y]=2*k-1;
    }
    while(k<m*m){
        state++;
        if(state==4)state=0;
        
        for(int j=0;j<step;j++){
        	k++;
        	if(state==0)y++;
        	else if(state==1)x++;
        	else if(state==2)y--;
        	else if(state==3)x--;
        	
        	
            /*if(odd==false)
        	    if(k>(m*m/2))
        	    mat[x][y] = 2*(k-(m*m/2));                
        	else if(odd==true )
        	    if(k>(m*m/2)+1)
        	    mat[x][y] = 2*(k-(m*m/2+1));*/
        	if(k>(m*m/2)+odd)
        	    mat[x][y] = 2*(k-(m*m/2+odd));
			else
			    mat[x][y] = 2*k-1;
    	}
		state++;
        if(state==4)state=0;
        for(int j=0;j<step;j++){
        	k++;
        	if(state==0)y++;
        	else if(state==1)x++;
        	else if(state==2)y--;
        	else if(state==3)x--;
        	
            /*if(odd==false)
        	    if(k>(m*m/2))
        	    mat[x][y] = 2*(k-(m*m/2));                
        	else if(odd==true )
        	    if(k>(m*m/2)+1)
        	    mat[x][y] = 2*(k-(m*m/2+1));*/
        	if(k>(m*m/2)+odd)
        	    mat[x][y] = 2*(k-(m*m/2+odd));			
			else
			    mat[x][y] = 2*k-1;
    	}
        step--;
    }
}

void Display2DArray(int **mat, const int m, const int n){



    for (int idx = 0 ; idx < m; idx++){

        for (int jdx = 0 ; jdx < n; jdx++)

        cout <<right<<setw(5)<< mat[idx][jdx];

    cout << endl;

    }
}

void Delete2DArray(int **mat, const int m){

 for (int idx = 0; idx < m; idx++)
 delete [] mat[idx];
 delete []mat;

}

