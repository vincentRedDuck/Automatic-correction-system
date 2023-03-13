#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

struct grade{
    string name;//student name
    int g1;//grade 1
    int g2;//grade 2
    int g3;//grade 3
    double avg;//average grade
};

const double Ngrade = 3;//number of grades set to 3, defined in double type to let division result comes with decimal

//Insertion Sort by Average grade
void InSA(grade *list, int num){
    for(int i = num-1; i >= 1; i--){
        grade swap;
        for(int j = 0; j < i; j++){
            if( list[i].avg < list[j].avg ){
                //put the 'i th' element into the swap space
                swap = list[i];
                for(int k = i-1; k >= j; k--){               
                    //move on to the next space
                    list[k+1] = list[k];                
                }
                //insert the content of swap space into the 'j th' element (empty now)
                list[j] = swap;
            }
        }
    }
}

//Insertion Sort by Name
void InSN(grade *list, int num){
    for(int i = num-1; i >= 1; i--){
        grade swap;
        for(int j = 0; j < i; j++){
            if( list[i].name < list[j].name ){
                //put the 'i th' element into the swap space
                swap = list[i];
                for(int k = i-1; k >= j; k--){               
                    //move on to the next space
                    list[k+1] = list[k];                
                }
                //insert the content of swap space into the 'j th' element (empty now)
                list[j] = swap;
            }
        }
    }
}
int main(int argc, char* argv[]){
    
    //name of the input file
    string iFn = argv[2];

    //decide the name of the output file based on the number of the arguments
    //given output file name (4 arguments)
    string oFn;
    if(argc == 4){
        oFn = argv[3];
    }
    //not given (3 arguments)
    else{
        int lenN = strlen(argv[2]);
        for(int a1 = 0; a1 <= lenN - 1; a1++){
            oFn += argv[2][a1];
        }
        oFn += ".out";
    }
    
    //define the input and output filestreams
    ifstream iFs;
    ofstream oFs;
    
    //open the demanded files
    iFs.open(iFn.c_str());
    oFs.open(oFn.c_str(), ios::out);
    
    //stringstream receiving getline data
    stringstream getL;
    
    //obtain the number of the students
    int num;
    iFs >> num;

    //define a grade list array with num of elements to store data
    grade *arr = new grade [num];

    for(int i=0; i < num; i++){
        iFs >> arr[i].name >> arr[i].g1 >> arr[i].g2 >> arr[i].g3;
        arr[i].avg = (arr[i].g1 + arr[i].g2 + arr[i].g3)/Ngrade;
    }

    //deciding the output format by argument 1, since legal argv[1] only contains 1 and 2, so we only have to test the first digit, which is argv[1][0]
    switch((int)argv[1][0] - (int)'0'){
        case 1:{
            InSA(arr, num);
            break;
        }
        case 2:{
            InSN(arr, num);
            break;
        }
        default:{
            cout << "Invalid input in argv[1], you debil, blyat!" << endl;
            return -1;
        }
    }
    for(int i=0; i < num; i++){
        oFs <<  arr[i].name << " "<< arr[i].g1 << " " << arr[i].g2 << " "<< arr[i].g3 << " "  << setprecision(4) << fixed << arr[i].avg << endl;
    }
    iFs.close();
    oFs.close();
    delete []  arr;
}
