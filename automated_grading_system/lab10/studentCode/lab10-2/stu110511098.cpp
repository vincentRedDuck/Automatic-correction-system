#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

const int MAX=500;

struct data{
    string num;
    string j_name;
    string e_name;
    string ot_name;
};

/*void sort(data vec[], int len){
    for(int j = 1; j < len; j++){
        data key(vec[j]);
        int i = j-1;
        while((i >= 0)&&vec[i].num > key.num){
            vec[i+1]=vec[i];
            i--;
        }
        vec[i+1] = key;
    }
}*/

int main(int argc, char *argv[]){
    ifstream inf;
    ofstream outf;
    inf.open(argv[1]);
    outf.open(argv[2]);
    data poke[MAX];
    istringstream iss;
    string line;
    int i=0;
    while(getline(inf,line)){
        iss.str(line);
        iss >> poke[i].num >> poke[i].j_name >> poke[i].e_name >> poke[i].ot_name ;
        //cout<< poke[i].num << poke[i].j_name << poke[i].e_name << poke[i].ot_name << endl;
        outf << poke[i].num <<" "<< poke[i].e_name <<" "<< poke[i].ot_name << endl;
        iss.clear();
        iss.str("");
        i++;
    }
    inf.close(); outf.close();
    
    inf.open(argv[3]);
    outf.open(argv[4]);
    string clct;
    //data mine[MAX];
    int mine[MAX] = {0};
    //int k=0;
    while(inf >> clct){
        for(int n=0;n<i+1;n++){
            /*if((atoi(clct.c_str()) == atoi((poke[n].num).c_str())||clct == poke[n].e_name)&&clct != mine[k-1].e_name){
                mine[k].num = poke[n].num;
                mine[k].e_name = poke[n].e_name;
                k++;*/
            if (atoi(clct.c_str()) == atoi((poke[n].num).c_str())) ++mine[n];
            if (clct == poke[n].e_name) ++mine[n];
            
        }
    }    
    //sort(mine,k);
    for(int idx = 0;idx < MAX;idx++){
        if(mine[idx] != 0 && idx < 493)
        outf << idx+1 <<" "<< poke[idx].e_name <<endl;
    }

    inf.close(); outf.close();

    return 0;
}
