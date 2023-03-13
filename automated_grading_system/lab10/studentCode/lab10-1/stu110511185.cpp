#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
/*void scrap(string wsite){
    //string tgt;//target
    //cin >> tgt;
    
    istringstream target(wsite);
    string trash;//useless data
    string Dn;//domain name
    string Md;//Method
    string ofcs;//other functions
    string fcn;//function name 
    string cont;//content
    getline(target, trash, '/');
    getline(target, trash, '/');
    oF << "=====" << endl;
    getline(target, Dn, '/');
    oF << "Domain name: "<< Dn << endl;
    getline(target, Md, '?');
    oF << "Method: " << Md << endl;
    while(getline(target, ofcs, '&' )){
        stringstream ofc(ofcs);
        getline(ofc, fcn, '=');
        getline(ofc, cont);
        if(fcn!="" && cont!=""){
            oF << fcn << ": " << cont << endl;
        }
    }
}*/
int main(int argc, char* argv[]){
    string inFn = argv[1];
    string outFn = argv[2];
    ifstream iF;
    iF.open(inFn.c_str());
    ofstream oF;
    oF.open(outFn.c_str(),ios::out);
    string site;
    while(getline(iF, site)){
        stringstream target(site);
        string trash;//useless data
        string Dn;//domain name
        string Md;//Method
        string ofcs;//other functions
        string fcn;//function name 
        string cont;//content
        getline(target, trash, '/');
        getline(target, trash, '/');
        oF << "=====" << endl;
        getline(target, Dn, '/');
        oF << "Domain name: "<< Dn << endl;
        int lq = site.find('?');//location of ?
        int lls;//location of last slash
        int idx = lq;
        while(site[idx]!='/'){
            idx--;
        }
        lls = idx;
        //while(getline(target, trash, '/'));
        //getline(target, Md, '?');
        Md = site.substr(lls+1, (lq-1)-(lls+1)+1);
        oF << "Method: " << Md << endl;
        getline(target, trash, '?');
        while(getline(target, ofcs, '&' )){
            stringstream ofc(ofcs);
            getline(ofc, fcn, '=');
            getline(ofc, cont);
                if(fcn!="" && cont!=""){
                oF << fcn << ": " << cont << endl;
            }
        }
    }    
    oF << "=====" << endl;
    iF.close();
    oF.close();
    return 0;
}
