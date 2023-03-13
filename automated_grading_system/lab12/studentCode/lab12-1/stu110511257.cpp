#include <iostream>
#include <iomanip>
using namespace std;

int main () {

    int len;
    cin >> len;
    
    while (len!=-1) {
        int **vec = new int *[len];
        for (int i=0; i<len; i++) 
            vec[i] = new int [len];

        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                vec[i][j] = 0;
            }
        }


        int x(0), y(0), set(0);
        int num1(0);
        int num2(1);
        while (set < len*len) {
       
            if (((x >= y) && (x+y < len-1)) || (len == 1)) {
                if (vec[y][x] != 0) {
                    x++; 
                    y++;
                }

                if (set < (len*len+1) / 2)
                    vec[y][x++] = 2*(num1++)+1;
                else 
                    vec[y][x++] = 2*(num2++);
                set++;
            }
            else if ((x+y >= len-1) && (x > y)) {
                if (vec[y][x] != 0) {
                    x--; 
                    y++;
                }

                if (set < (len*len+1) / 2)
                    vec[y++][x] = 2*(num1++)+1;
                else 
                    vec[y++][x] = 2*(num2++);
                set++;
            }
       
            else if ((x <= y) && (x+y > len-1)) {
                if (vec[y][x] != 0) {
                    x--;
                    y--;
                }

                if (set < (len*len+1) / 2)
                    vec[y][x--] = 2*(num1++)+1;
                else 
                    vec[y][x--] = 2*(num2++);
                set++;
            }

            else if ((x+y <= len-1) && (x < y)) {
                if (vec[y][x] != 0) {
                    x++;
                    y--;
                }
            
                if (set < (len*len+1) / 2)
                    vec[y--][x] = 2*(num1++)+1;
                else 
                    vec[y--][x] = 2*(num2++);
                set++;
            }

            else {
                cout << "Error..." << y << " " << x << endl;
                set++;
            }
        }



        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                cout << setw(5) << right << vec[i][j];
            } cout << endl;
        }


        cin >> len;
    }



    return 0;
}
