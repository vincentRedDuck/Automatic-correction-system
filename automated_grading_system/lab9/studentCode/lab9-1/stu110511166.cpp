#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[]){
    ifstream infile;
    infile.open(argv[1]);
    int x[100]={0};
    int i = 0;
        string s;
    while(getline(infile, s)){
        
        int p = s.find(':');
        //cout << s.substr(p+1, s.size()-p);
        if(p!=s.size()-1){
            x[i] = stoi(s.substr(p+1, s.size()-p));
            i++;
        }
        else{
            x[i] = 0;
            i++;
        }
       }
    cout << "i=" << i << endl;
    int sum = 0;
    for(int k = 0; k < i; k++){
        sum += x[k];  
        cout << x[k] << " | " << k << " =" << sum << endl;
    }
    double res = sum/(i*1.0);
    /*for(int i = 0; i <100; i++){
        if(x[i]!=0) cout << x[i];
    }*/
    infile.close();
    ofstream outfile;
    outfile.open(argv[2]);
    outfile << "The average is: " << fixed << setprecision(4) << res;
    outfile.close();
    
            
    return 0;
}
