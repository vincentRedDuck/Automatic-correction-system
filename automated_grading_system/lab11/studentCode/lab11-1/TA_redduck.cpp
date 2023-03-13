#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "ex11-1.h"

using namespace std;

#define ARRAYSIZE 10

int main(int argc, char *argv[]){
    fstream *fp;
    int *arr[ARRAYSIZE];

    fp = open_fstream(argv[1]);
    for (int i = 0; i < ARRAYSIZE; i++)
        arr[i] = new int;

    for (int i = 0; i < ARRAYSIZE; i++)
        set_number_from_file(fp, arr[i], (int *)(&(arr[i])));                        

    for (int i = 0 ; i < ARRAYSIZE; i++)         
        show_arr_element(arr[i], (int *)(&(arr[i])));    
    cout << endl;
    
    close_fstream(fp);
    return 0;
}

