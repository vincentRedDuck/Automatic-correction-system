#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//struct for new pokedex
struct ndx{
    int num;
    string numS;//number (string type)
    string En;//English name
    string OTn;//Offical Taiwanese name
};

//struct for old pokedex
struct odx{

    string numS;//number (string type)
    string Jn;//Japanese name
    string En;//English name 
    string OTn;//Offical Taiwanese name
    string Cn;//Chinese name
};
    
//lup.open(nDx.c_str());
/*
//search by English name 
ndx search(string En){
    ifstream lup;//looking up the new index
    lup.open("Pokedex.in");
    string lookup;
    ndx data = {0,0,0};
    while(getline(lup,lookup)){
        stringstream dIn;
        dIn >> data.num >> data.En >> data.OTn;
        if(data.En == En){
            return data;
        }
    }
    return data;
}*/

int main(int argc, char* argv[]){
    //Making new pokedex
    string oDx = argv[1];//old pokedex
    string nDx = argv[2];//new pokedex
    string uL = argv[3];//unsorted list
    string sL = argv[4];//sorted list
    ifstream iF;
    ofstream oF;
    iF.open(oDx.c_str());
    oF.open(nDx.c_str());
    string tgt;//processing target
    while(getline(iF, tgt)){
        odx iD;
        ndx oD;
        stringstream swap;
        swap.str(tgt);
        swap >> iD.numS >> iD.Jn >> iD.En >> iD.OTn >> iD.Cn;
        oD.numS = iD.numS;
        oD.En = iD.En;
        oD.OTn = iD.OTn;
        oF << oD.numS << " " << oD.En << " " << oD.OTn << endl;
    }
    
    iF.close();
    oF.close();
    
    
    ifstream lup;

    //checking what pokemons appeared in the list
    bool ex[494] = {false};//left ex[0] empty, and other index matches the number in the Pokedex
    iF.open(uL);
    string line;
    string pok;//pokemon input, can be English name or number
    while(!iF.eof()){
        iF >> pok;
        //cout << pok << endl;
        //if the first char is a number, then it is the number of a pokemon
            if((int)'0'<=(int)pok[0] && (int)pok[0]<=(int)'9'){
                ex[stoi(pok)] = true;
    
                //cout << stoi(pok) << endl;
                //cout << ex[stoi(pok)] << endl;
            }
            //if not, it is the name, and look it up in the nex pokedex 
            else{
                //cout << pok << endl;
                string idxin;//storing getline from the new pokedex
                ndx in;//extracted data from the idxin
                lup.open(nDx.c_str());
                while(!lup.eof()){
                    
                    stringstream input;//ss for input data
                    input.str(idxin);
                    lup >> in.num >> in.En >> in.OTn;
                    //cout << in.En << endl; 
                    if(pok == in.En) {
                        //cout <<  in.num << endl;
                        ex[in.num] = true;
                        break;
                        //cout << ex[in.num] << endl;
                        //cout << num << endl;
                        //cout << in.num << in.En << in.OTn << endl;
                      
                    }        
                }
                lup.close();
            }
        }
    
    

    //print out existed pokemons
    oF.open(sL.c_str());
    for(int i=1; i<=493; i++){
        //cout << ex[i];
        if(ex[i] == true){
            //cout << i << " " << ex[i] << endl;
            string idxin;
            lup.open(nDx.c_str());
            while(!lup.eof()){
                ndx in;
                stringstream input;
                input.str(idxin);
                lup >> in.num >> in.En >> in.OTn;
                //cout << in.num << in.En << in.OTn << endl;
                if(i == in.num){
                    oF << in.num << " " << in.En << endl;    
                    break;
                }        
            }

            lup.close();
        }
    }
    /*
    string pok;
    ndx data;
    cin >> pok;
    data = search(pok);
    cout << data.num << data.En << data.OTn << endl;*/
}
