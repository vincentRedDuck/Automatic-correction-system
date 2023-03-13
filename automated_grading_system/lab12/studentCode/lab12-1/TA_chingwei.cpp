#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int** new2DArray(const int);
void initial2DArray(int **, const int);
void display(int **);
void normal_display(int **, const int);
void delete2DArray(int **, const int);

int main() {
    int size;
    cin >> size;
    while (size != -1) {
        int **vec = new2DArray(size);
        initial2DArray(vec, size);
        //normal_display(vec, size);
        int num = 0, i = 0, j = 0, val = 1;
        while (num <= size * size) {
            while (j < size) {
                if(vec[i][j]==0) {
                    if (val > size * size) {
                        val = 2;
                    } else {
                        vec[i][j++] = val;
                        val += 2;
                    }
                    num++;  
                } else
                    break;
            }
            j--;
            i++;
            while (i < size) {
               if(vec[i][j]==0) {
                    if (val > size * size) {
                        val = 2;
                    } else {
                        vec[i++][j] = val;
                        val += 2;
                    }
                    num++;  
                } else
                    break;
            }
            i--; j--;
            while (j >= 0) {
               if(vec[i][j]==0) {
                    if (val > size * size) {
                        val = 2;
                    } else {
                        vec[i][j--] = val;
                        val += 2;
                    }
                    num++;  
                } else
                    break;
            }
            j++; i--;
            while (i >= 0) {
               if(vec[i][j]==0) {
                    if (val > size * size) {
                        val = 2;
                    } else {
                        vec[i--][j] = val;
                        val += 2;
                    }
                    num++;  
                } else
                    break;
            }
            i++; j++;
            //cout << "i = " << i << ", j = " << j << endl;
        }
        normal_display(vec, size);
        cin >> size;
    }
    return 0;
}

int** new2DArray(const int m) {
    int **mat = new int *[m];
    for (int idx = 0; idx < m; idx++)
        mat[idx] = new int [m];
    return mat;
}

void initial2DArray(int **v, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            v[i][j] = 0;
        }
    }
}

void normal_display(int **v, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(5) << right << v[i][j] ;
        }
        cout << endl;
    }
}

void delete2DArray(int **v, const int size) {
    for(int i = 0; i < size; i++)
        delete [] v[i];  
    delete [] v;
}