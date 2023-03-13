#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
struct morse{
    char alnu;
    string momo;
    };
int main(int argc, char *argv[]){
    ifstream in_file;
    in_file.open("code.txt");
    morse mos[36];
    for(int i = 0; i<36; i++){
    in_file >> mos[i].alnu >> mos[i].momo;
    }
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    outfile.open(argv[2]);
    if(string(argv[3])=="e"){
        string line;
        while(getline(infile,line)){
            string x[100];
            int beg = 0, n = 0;
            for(int i = 0; i<=line.length(); i++){
                if(line[i] == ' ' || i == line.length()){
                    x[n++] = line.substr(beg,i-beg);
                    beg = i+1;
                }
            }
            /*for(int i = 0; i<n; i++)
                cout << x[i] << ",";
                cout << endl;*/
            for(int i = 0; i<n; i++){
                string y = x[i];
                for(int j = 0; j<y.length(); j++){
                    for(int k = 0; k<36; k++){
                        if(y[j] == mos[k].alnu){
                            outfile << mos[k].momo;
                            outfile << (j != (y.length()-1)? "   ": "       "); 
                        }   
                    }
                }
            }
            outfile << endl;    
        }
        outfile << endl;
    }
    else if(string(argv[3])=="d"){
        string line;
        while(getline(infile,line)){
            string x[100];
            int beg = 0, n = 0;
            for(int i = 0; i<=line.length(); i++){
                if(line.substr(i,3) == "   " || i == line.length()){
                    x[n++] = line.substr(beg,i-beg);
                    beg = i+3;
                }
                if(line.substr(i,7) == "       ")
                    x[n++] = " ";
            }
            /*for(int i = 0; i<n; i++)
                cout << x[i] << ",";
                cout << endl;*/
            for(int i = 0; i<n; i++){
                string y = x[i];
                //for(int j = 0; j<y.length(); j++){
                    for(int k = 0; k<36; k++){
                        if(y == mos[k].momo)
                            outfile << mos[k].alnu;
                    }
                if(x[i+1]==" ") 
                    outfile << " ";    
            }
            outfile << endl;
        }    
    }
    in_file.close();outfile.close();infile.close(); 
    return 0;
}
