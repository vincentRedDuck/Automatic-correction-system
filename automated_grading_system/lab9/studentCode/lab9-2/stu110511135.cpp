#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
struct person{
    string name;
    int g1;
    int g2;
    int g3;
    double avg;
};
void sortperson1(person[], int);
void sortperson2(person[], int);
void out(person[], ofstream&, int);
int main(int argc, char *argv[]){
    char *infile = argv[2];
    char *mode = argv[1];   
    char *outfile = argv[3]; 
    person persons[100];
    ifstream fin(infile);
    int num, count=0;
    char ch;
    fin >> num;
    for(int i=0; i<100; i++){
        fin.get(ch);
        if(fin.eof()){
            break;
        }
        fin >> persons[i].name;
        fin >> persons[i].g1;
        fin >> persons[i].g2;
        fin >> persons[i].g3;
        persons[i].avg = (persons[i].g1 + persons[i].g2 + persons[i].g3)/3.0;
        count = i;
    }

    if(!strcmp(mode,"1")){
        sortperson1(persons, count);
        char *outfile = strcat(infile, ".out");
        ofstream fout(outfile);
        out(persons, fout, count);
    }else if(!strcmp(mode, "2")){
        sortperson2(persons, count);
        ofstream fout(outfile);
        out(persons, fout, count);
    }

return 0;
}

void sortperson1(person a[], int len){
    for (int j=1; j<len; j++) {
        person key = a[j];
        int i = j-1;
        while (i>=0 && a[i].avg>key.avg) {
            a[i+1] = a[i];
            i--; 
        }
        a[i+1] = key;
    }

}
void sortperson2(person a[], int len){
    for (int j=1; j<len; j++) {
        person key = a[j];
        int i = j-1;
        while (i>=0 && strcmp(a[i].name.c_str(), key.name.c_str())>0) {
        a[i+1] = a[i];
        i--; 
        }
        a[i+1] = key;
    }
}
void out(person a[], ofstream& fout, int len){
    for(int i=0; i<len; i++){
        fout << fixed << setprecision(4) << a[i].name << ' ' << a[i].g1 << ' ' << a[i].g2 << ' ' << a[i]    .g3 << ' ' << a[i].avg << endl;
    }
}


