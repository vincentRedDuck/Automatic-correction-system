#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;
struct namegrade{
    string f;
    int x;
    int y;
    int z;
    double av;
};
int main(int argc, char *argv[]){
    ifstream fin;
    fin.open(argv[2]);  
    string a;
    getline(fin, a);
    int n = stoi(a.c_str());
    namegrade *s = new namegrade[n];
    int i = 0;
    while(getline(fin, a)){
        stringstream ll(a);
        ll >> s[i].f >> s[i].x >> s[i].y >> s[i].z;
        s[i].av = (s[i].x + s[i].y + s[i].z)/3.0;
        i++;
    }
    if(stoi(argv[1])==1){
     for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (s[j].av > s[j+1].av) {
                namegrade temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;}}}
    }
    else{
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-i-1; j++) {
                if (s[j].f > s[j+1].f) {
                    namegrade temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;}}}

        }
    ofstream fout;
    string name(argv[2]);
    fout.open((argc == 3)?name+".out":argv[3]);
    for(int j = 0; j < i; j++){
        fout << s[j].f << " " << s[j].x << " " << s[j].y << " " << s[j].z << " "  << fixed << setprecision(4)<< s[j].av << endl;
    }
    /*for(int j = 0;j < i; j++ ){
        cout << s[j].f << " ";
    }*/
    fin.close();
    fout.close();
    return 0;
}
