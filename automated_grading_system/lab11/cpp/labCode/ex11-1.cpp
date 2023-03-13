#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#define ARRAYSIZE 10

fstream* initializeFstream(string FilePath){
    //============= student code =================
    //you need create fstream object and then open the file
    fstream *fp;
    fp = new fstream;
    fp->open(FilePath, ios::in);

    return fp;
   //============ student code end ===============    
}

void updateElement(int *element, fstream *fp){
    //============= student code =================
    //update one element of the numbers array.
    string strNum;    
    getline(*fp, strNum, ',');      
    *element = stoi(strNum);
   //============ student code end ===============    
}


int main(int argc, char *argv[]){
    fstream *fp;
    int numbers[ARRAYSIZE];

    fp = initializeFstream(argv[1]);

    for(int i = 0; i < ARRAYSIZE; i++){
        updateElement(&numbers[i], fp);
        cout << numbers[i] << " ";
    }    
    cout << endl;

    return 0;
}

