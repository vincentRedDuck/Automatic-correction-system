#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int size;
    cin >> size;
    while (size != -1) {
        int **arr = new int *[size];
        for (int i=0; i<size; i++) {
            arr[i] = new int [size];
        }
        int num = 1,i=0,j=0,count=0;

        for (int k=0; count != size*size; k++) {
            i = k; j = k;
            for (; j<size-k; j++) {
                if (count == size*size) break;
                if (num > size * size) num = 2;
                arr[i][j] = num;
                num += 2;
                count++;
            }
            j--;
            for (i = i+1; i<size-k; i++) {
                if (count == size*size) break;
                if (num > size * size) num = 2;
                arr[i][j] = num;
                num += 2;
                count++;
            }
            i--;
            for (j = j-1; j>=k; j--) {
                if (count == size*size) break;
                if (num > size * size) num = 2;
                arr[i][j] = num;
                num += 2;
                count++;
            }
            j++;
            for (i = i-1; i>=k+1; i--) {
                if (count == size*size) break;
                if (num > size * size) num = 2;
                arr[i][j] = num;
                num += 2;
                count++;
            }
            i++;
            if (count == size*size) break;
        }

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                cout << setw(5) << right << arr[i][j];
            }
            cout << endl;
        }

        for (int i=0; i<size; i++)
            delete [] arr[i];
        delete [] arr;

        cin >> size;
    }
}
