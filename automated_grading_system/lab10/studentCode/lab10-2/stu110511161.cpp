#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

struct pok{
    string num;
    string name;
};

int main(int argc, char *argv[]){
    int count=0;
    pok p[493];
    int sort[493]={0};
    istringstream iss;
    string a,b,c,d,e,str;
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in_f" << endl;
    ofstream out_file;
    out_file.open(argv[2]);
    if(out_file.fail())cout << "ERROR out_f" << endl;

    while(getline(in_file, str)){
        iss.str(str);
        iss >> a >> b >> c >> d >> e;
        out_file << a << " " << c << " " << d << endl;
        p[count].num = a;
        p[count].name = c;
        count++;
        iss.clear();
    } 

    in_file.close();
    out_file.close();

    ifstream id;
    id.open(argv[3]);
    if(id.fail())cout << "ERROR id" << endl;
    ofstream out;
    out.open(argv[4]);
    if(out.fail())cout << "ERROR out" << endl;
    a.clear(); str.clear();
    while(getline(id, a)){
        str += a;
        str += " ";
    }
    iss.str(str); a.clear();
    while(iss >> a){
        for(int i=0; i<493; i++){
            
            if(atoi(a.c_str()) == atoi(p[i].num.c_str())){
                sort[i]++;
                break;
            }
            if(a == p[i].name){
                sort[i]++;
                break;
            }
        }
    }

    for(int i=0; i<493; i++){
        if(sort[i]>0){
            out << stoi(p[i].num) << " " << p[i].name << endl;
        }
    }
    
    id.close();
    out.close();
    return 0;
}
