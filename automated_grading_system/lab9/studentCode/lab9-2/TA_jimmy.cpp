#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>

using namespace std;

struct stu_for_one{
    int grades[3];
    string name;
};
struct stu_for_two{
    int grades[3];
    double ttl;
};

int main(int argc, char* argv[]){
    ifstream in(argv[2]);
    string run;
    getline(in, run, '\n');

    if(atoi(argv[1]) == 1){
        map<int, stu_for_one> my;

        while(getline(in, run, '\n')){
            stu_for_one tmp;
            stringstream ss;
            ss << run;
            ss >> tmp.name >> tmp.grades[0] >> tmp.grades[1] >> tmp.grades[2];
            int ttl = tmp.grades[0] + tmp.grades[1] + tmp.grades[2];
            my.insert(pair<int, stu_for_one>(ttl, tmp));
        }
        if(argc == 3){
            ofstream out((string(argv[2]) + ".out" ).c_str());
            for(map<int, stu_for_one>::iterator it = my.begin() ; it != my.end() ; it++ )
                out << it->second.name << " " << it->second.grades[0]
                                       << " " << it->second.grades[1]
                                       << " " << it->second.grades[2]
                                       << " " << fixed << setprecision(4) << it->first / 3.0 << endl;
            out.close();
        }
        else if(argc == 4){
            ofstream out(argv[3]);
            for(map<int, stu_for_one>::iterator it = my.begin() ; it != my.end() ; it++ )
                out << it->second.name << " " << it->second.grades[0]
                                       << " " << it->second.grades[1]
                                       << " " << it->second.grades[2]
                                       << " " << fixed << setprecision(4) << it->first / 3.0 << endl;
            out.close();
        }
    }
    else if(atoi(argv[1]) == 2){
        map<string, stu_for_two> my;

        while(getline(in, run, '\n')){
            string name;
            stu_for_two tmp;
            stringstream ss;
            ss << run;
            ss >> name >> tmp.grades[0] >> tmp.grades[1] >> tmp.grades[2];
            tmp.ttl = tmp.grades[0] + tmp.grades[1] + tmp.grades[2];
            my.insert(pair<string, stu_for_two>(name, tmp));
        }
        if(argc == 3){
            ofstream out((string(argv[2]) + ".out" ).c_str());
            for(map<string, stu_for_two>::iterator it = my.begin() ; it != my.end() ; it++ )
                out << it->first << " " << it->second.grades[0]
                                 << " " << it->second.grades[1]
                                 << " " << it->second.grades[2]
                                 << " " << fixed << setprecision(4) << it->second.ttl / 3.0 << endl;
            out.close();
        }
        else if(argc == 4){
            ofstream out(argv[3]);
            for(map<string, stu_for_two>::iterator it = my.begin() ; it != my.end() ; it++ )
                out << it->first << " " << it->second.grades[0]
                                 << " " << it->second.grades[1]
                                 << " " << it->second.grades[2]
                                 << " " << fixed << setprecision(4) << it->second.ttl / 3.0 << endl;
            out.close();
        }
    } 
    return 0;
}