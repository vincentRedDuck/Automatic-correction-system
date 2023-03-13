#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
struct twos{
    string a[2];
};
int see1(string a){
    int nu=0;
    for(int i=0;i<a.length();i++){
        if(isdigit(a[i])){
            nu=i;
        }  
        if( isdigit(a[i]) && ! (isdigit(a[i+1]) ))
            break;      
    }
    return nu;
}
int see2(string a){
    int nu;
    for(int i=0;i<a.length();i++){
        if(('A'<=(a[i])&&a[i]<='Z')|| ('a'<=a[i]&&a[i]<='z') )
            return i;
    }
    return -1; 
}
int see3(string a,int ini){
    int nu=0;
    for(int i=ini;i<a.length();i++){
        if( a[i]==' ' && (isalpha(a[i+1]))&&isalpha(a[i-1]) ) 
            nu++;
        if( !(isalpha(a[i])) && !(isalpha(a[i+1]))&&!( isalpha(a[i-1]) ) )
            break;
    }
    return nu;
}
int main(int argc, char* argv[]) {

    ifstream infile1(argv[1]), infile2(argv[3]);
    ofstream outfile1(argv[2]), outfile2(argv[4]);
    string str;
    while( getline(infile1,str) ){
        string a;
        //int nu1 = see1(str) , nu2 ;
        //int nu3 = see3(str,nu2);
        //str.erase(nu1+2,nu2-nu1-2);
        stringstream ss; ss.str(str);
        int nu=0; 
        while(ss>>a){
            if(nu==1){
                nu++;
                continue;
            }
            if(nu== 4 )
                break;
            outfile1<<a<<" ";
            nu++;
        }
        outfile1<<endl;
    }
    outfile1.close();
    ifstream infile3(argv[2]);
    str="";
    twos load[1000]; int totalc=0;
    while (infile2 >> str) {
        int count = 0; int j = 0;
        string b;
        while (getline(infile3, b)) {
            count++;
            stringstream ss; ss.str(b);
            string scm;
            for (int i = 0; i < 2; i++) {
                ss >> scm; load[totalc].a[i] = scm;
            }
            if (load[totalc].a[1] == str) {
                break;
            }
            else if (isalpha(str[1]))
                continue;
            else if( stoi( load[totalc].a[0] )== stoi(str) ) {
                break;
            }
        }
        totalc++;
        infile3.close();
        infile3.open(argv[2]);
    }
    for (int i = 1; i < totalc; i++) {
        twos key = load[i];
        int j = i - 1;
        while (j >= 0 && load[j].a[0] > key.a[0]) {
            load[j + 1] = load[j];
            j--;
        }
        load[j + 1] = key;
    }
    for (int i = 0; i < totalc; i++) {
        if (i == totalc-1 ) {
            outfile2 << stoi(load[i].a[0]) << " " << load[i].a[1] << endl;
            break;
        }
        if (load[i].a[0] == load[i + 1].a[0])
            continue;
        outfile2 <<stoi( load[i].a[0] ) << " " << load[i].a[1] << endl;
    }
}

