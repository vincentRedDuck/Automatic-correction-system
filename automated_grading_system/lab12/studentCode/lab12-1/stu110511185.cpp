#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
int main()
{
    int n;//width of the square int array
    cin >> n;
    
    while(n >= 0){
        int **elmX;
        elmX = new int* [n];
        for(int a=0; a < n; a++){
            elmX[a] = new int [n];
        }
        int data = 1 ;//the number which is going to write into the array
        int dir = 0;//direction: 0 for right, 1 for down, 2 for left, 3 for up
        int cir = 0;//the number of the circle, from outside to inside, a maze of size n*n has (n+1)/2 circles
    
        //index in two dimensions
        int x = 0;
        int y = 0;
        while(cir <= (n+1)/2 - 1){
            //cout << data << endl;
            //assigning data to the element
            elmX[x][y] = data;
            //cout << "(" << x <<", " <<y << ")"<< elmX[x][y] << endl;
            //cout << x << " " << y << endl;
            //sleep(1);

            //updating the data
                data += 2;
                if(data > n*n){
                    data = 2;//change to even number if odd number part has completed
                }

            //changing direction
            if(dir == 0 && x == (n-1) - cir){
                dir = 1;//reaching the upright corner of the circle
            }
        
            else if(dir == 1 && y == (n-1) - cir){
                dir = 2;//reaching the downright corner of the circle
            }

            else if(dir == 2 && x == cir){
                dir = 3;//reaching the downleft corner of the circle
            }

            else if(dir == 3 && y == cir+1){
                dir = 0;//reaching one blank lower the upleft corner circle
                cir ++;
            }
        
            //move the index following the direction
            switch(dir){
                case 0:{
                    x++;
                    break;
                }
                case 1:{
                    y++;
                    break;
                }
                case 2:{
                    x--;
                    break;
                }
                case 3:{
                    y--;
                    break;
                }  
            }
            if( (n%2 == 0 && data == n*n) || (n%2 == 1 && data == n*n - 1) ){
                elmX[x][y] = data;
                break;
            }
        }


        //printing out 
        for (int i = 0; i < n; i++){
            for (int j=0; j < n; j++){
                cout << setw(5) << right <<  elmX[j][i];
            }
            cout << endl;
        }
        cout << endl;
        for (int a=0; a < n; a++){
            delete []  elmX[a];
        }
        delete [] elmX;
        cin >> n;
    }
    return 0;
}
