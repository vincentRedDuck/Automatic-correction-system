#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct stu{
    string name;
    double s1;
    double s2;
    double s3;
    double avg;
};

int main(int argc, char *argv[]){
    ifstream in_file;
    in_file.open(argv[2]);
    if(in_file.fail())cout << "ERROR" << endl;
    string str, temp;
    getline(in_file, str);
    int n = stoi(str), i=0;
    stu id[n];
    stu swp;

    while(getline(in_file, str)){
        id[i].name = str.substr(0, str.find(" "));
        str.erase(0, str.find(" ")+1);

        temp = str.substr(0, str.find(" "));
        id[i].s1 = stoi(temp);
        str.erase(0, str.find(" ")+1);

        temp = str.substr(0, str.find(" "));
        id[i].s2 = stoi(temp);
        str.erase(0, str.find(" ")+1);

        id[i].s3 = stoi(str);
        id[i].avg = (id[i].s1+id[i].s2+id[i].s3)/3;
        //cout << fixed << setprecision(4) << id[i].avg << endl;
        i++;
    }

    if(strcmp(argv[1], "1")==0){
        //cout << "hi";
        for(int k=0; k<n; k++){
            for(int h=k+1; h<n; h++){
                if(id[k].avg>id[h].avg){
                    swp = id[k];
                    id[k] = id[h];
                    id[h] = swp;
                }
            }
        }
        /*for(int l=0; l<n; l++){
            cout << id[l].name << " " << fixed << setprecision(0) << id[l].s1 << " " << id[l].s2 << " " << id[l].s3 << " " << fixed << setprecision(4) << id[l].avg << endl;
        }*/
    }

    if(strcmp(argv[1], "2")==0){
        //cout << "hi";
        for(int k=0; k<n; k++){
            for(int h=k+1; h<n; h++){
                if(id[k].name.compare(id[h].name)>0){
                    swp = id[k];
                    id[k] = id[h];
                    id[h] = swp;
                }
            }
        }
        /*for(int l=0; l<n; l++){
            cout << id[l].name << " " << fixed << setprecision(0) << id[l].s1 << " " << id[l].s2 << " " << id[l].s3 << " " << fixed << setprecision(4) << id[l].avg << endl;
        }*/
    }

    ofstream out_file;
    if(argc==3){
        string str3 = argv[2] + string(".out");
        out_file.open(str3, ios::trunc);
        for(int l=0; l<n; l++){
            out_file << id[l].name << " " << fixed << setprecision(0) << id[l].s1 << " " << id[l].s2 << " " << id[l].s3 << " " << fixed << setprecision(4) << id[l].avg << endl;
        }
    }

    else{
        out_file.open(argv[3], ios::trunc);
        for(int l=0; l<n; l++){
            out_file << id[l].name << " " << fixed << setprecision(0) << id[l].s1 << " " << id[l].s2 << " " << id[l].s3 << " " << fixed << setprecision(4) << id[l].avg << endl;
        }
    }

    return 0;
}
