#include <bits/stdc++.h>
using namespace std;
void f(int row, int **arr){
	int c;
    int j=0;
    int i=0;
    int start = 1;
    int rowTmp;
    rowTmp=row;
    for(c=0; c< rowTmp/2; c++)
	{
      //  if(row*row %2 == 0)
      //  {
      //      if(start == row*row-1) {
      //          start=0;
      //          //cout<<"D1:"<<endl;
      //      }
      //  }
      //  else if(row*row %2 == 1)
      //  {
      //      if(start == row*row) {
      //          start=0;
      //          //cout<<"D2:"<<endl;
      //      }
      //  }
        //cout <<"D3 Start=" <<start<< ";row="<<row<< ";c=" << c << ";i=" <<i << ";j=" << j <<endl;
        for(;j+1<row; j++ )
        {   
            arr[i][j+1] = start + 2;
            start+=2;
            //cout<<"D3="<< arr[i][j+1]  <<endl;
            if(rowTmp*rowTmp %2 == 0)
            {
                if(start == rowTmp*rowTmp-1) {
                    start=0;
                    //cout<<"D1:"<<endl;
                }
            }
            else if(rowTmp*rowTmp %2 == 1)
            {
                if(start == rowTmp*rowTmp) {
                    start=0;
                //cout<<"D2:"<<endl;
                }
            }

        }
       // cout <<"D4 Start=" <<start<< ";row="<<row<< ";c=" << c << ";i=" <<i << ";j=" << j <<endl;
        for(;i+1<row; i++)
        {   
            //cout <<"Ai=" <<i<<endl;
            arr[i+1][j] = start + 2;
            start+=2;
           // cout<<"D4="<< arr[i+1][j]  <<endl;
            if(rowTmp*rowTmp %2 == 0)
            {
                if(start == rowTmp*rowTmp-1) {
                    start=0;
                //cout<<"D1:"<<endl;
                }
            }
            else if(rowTmp*rowTmp %2 == 1)
            {
                if(start == rowTmp*rowTmp) {
                    start=0;
                //cout<<"D2:"<<endl;
                }
            }

        }
        //cout <<"Bi=" <<i<<endl;
        //cout <<"D5 Start=" <<start<< ";row="<<row<< ";c=" << c << ";i=" <<i << ";j=" << j <<endl;
        for(j=row-1; j>c; j--)
        {
            arr[i][j-1] = start + 2;
            start+=2;
            //cout<<"D5="<< arr[i][j]  <<endl;
            if(rowTmp*rowTmp %2 == 0)
            {
                if(start == rowTmp*rowTmp-1) {
                    start=0;
                //cout<<"D1:"<<endl;
                }
            }
            else if(rowTmp*rowTmp %2 == 1)
            {
                if(start == rowTmp*rowTmp) {
                    start=0;
               // cout<<"D2:"<<endl;
                }
            }

        }
       // cout <<"D6 Start=" <<start<< ";row="<<row<< ";c=" << c << ";i=" <<i << ";j=" << j <<endl;
        for(i=row-2;i>c;i--)
        {    
            arr[i][j] = start + 2;
            start+=2;
            //cout<<"D6="<< arr[i][j]  <<endl;
            if(rowTmp*rowTmp %2 == 0)
            {
                if(start == rowTmp*rowTmp-1) {
                    start=0;
                //cout<<"D1:"<<endl;
                }
            }
            else if(rowTmp*rowTmp %2 == 1)
            {
                if(start == rowTmp*rowTmp) {
                    start=0;
                //cout<<"D2:"<<endl;
                }
            }

        }
        i++;
       // j++;
        row--;
       // cout <<"D7 Start=" <<start<< ";row="<<row<< ";c=" << c << ";i=" <<i << ";j=" << j <<endl;
	}

   	if (rowTmp % 2 != 0) //如果size為奇數則最後中間那一個數遍歷不到，這裡補上
	{
	  arr[i][j + 1] = start +2 ;
	}
 
}
int main(){
    int row = 0;
    while(cin>>row)
    {
        if(row==-1)
            break;
        int **arr = new int *[row];
        for (int i = 0; i<row ;i++)
        {
            arr[i] = new int [row];
        }
        //set array = 0
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<row; j++)
            {
                arr[i][j] = 0;
            }
        }
        //print array
        arr[0][0] = 1;
        f(row, arr);
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<row; j++)
            {
                cout<<setw(5)<<arr[i][j];
                if (j==row-1)
                    cout<<endl;
            }
        }
        
        
        // cout << "finish" <<endl;
        for (int i=0; i<row; i++)
        {
            delete [] arr[i];
        }    delete [] arr;
        arr = NULL;
        
    }

    return 0;
}

