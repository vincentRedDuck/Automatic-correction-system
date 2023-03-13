#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]){
    ifstream in_file(argv[1]);
    string textline;
    int a, c = 0;
    float b = 0.0;
    while(getline(in_file,textline,'\n')){
        if(textline.erase(0,textline.find(":")+1) != "\0")
            a = stoi(textline.erase(0,textline.find(":")+1));
        else
            a = 0;  
        b += a;
        c++;
    }
    //cout << b/4.0 <<endl;
    ofstream myfile;
    myfile.open(argv[2]);
    myfile << fixed << setprecision(4) << "The average is: " << b/c;
    myfile.close();
    in_file.close();
    return 0;
}
