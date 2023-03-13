#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;
struct poki{
    int num;
    string strnum;
    string ename;
    string cname;
};
int main(int argc, char *argv[]){
    stringstream ss;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    string line, word;
    int count=0;
    while(getline(fin,line)){
        ss.str(line);
        ss >> word;
        fout << word << " ";
        ss >> word;
        ss >> word;
        fout << word << " ";
        ss >> word;
        fout << word << endl;
        ss.str("");
        ss.clear();
    }
    poki arr[493];
    fin.close();
    fin.open(argv[2]);
    ss.str("");
    ss.clear();
    for(int i=0; i<493; i++){
        getline(fin,line);
        ss.str(line);
        ss >> word;
        arr[i].strnum = word;
        arr[i].num = i+1;
        ss >> word;
        arr[i].ename = word;
        ss >> word;
        arr[i].cname = word;
//        cout << arr[i].num << " " << arr[i].strnum << " " << arr[i].ename << " " << arr[i].cname << endl;
        ss.str("");
        ss.clear();
    } 
    
    fin.close();
    fin.open(argv[3]);
    poki arr2[3000];
    while(fin>>word){
        for(int i=0; i<493; i++){
            if(!word.compare(arr[i].ename)||!word.compare(arr[i].cname)||!word.compare(arr[i].strnum)||atoi(word.c_str())==arr[i].num){
                arr2[count] = arr[i];            
            }
        }
        count++;
    }
/*    for(int i=0; i<count; i++){
        cout << arr2[i].strnum << " " << arr2[i].ename << endl;
    }*/
    for (int j=1; j<count; j++) {
        poki key = arr2[j];
        int i = j-1;
        while (i>=0 && arr2[i].num>key.num) {
            arr2[i+1] = arr2[i];
            i--; 
        }
        arr2[i+1] = key;
    } 
    fout.close();
    fout.open(argv[4]);
    bool flag=true;
    for(int i=0; i<count; i++){
        for(int j=0; j<count; j++){ 
            if(arr2[i].num==arr2[j].num&&j>i){flag=false;}
        }
        if(flag){
            fout << arr2[i].num << " " << arr2[i].ename << endl;
        }
        flag = true;
    }
    fout.close();
return 0;
}
