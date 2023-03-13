#include<bits/stdc++.h>

using namespace std;

void print(string,char[]);
int main(int k, char **argv){

ifstream F1(argv[1]);
ofstream a(argv[2]);
a.close();
string url,out;


    while(getline(F1,url)){
        ofstream o1(argv[2],ios::app);
        o1<<"====="<<endl;
          
        stringstream ss(url);
        getline(ss,out,'/');
        getline(ss,out,'/');
        getline(ss,out,'/');
        o1<<"Domain name: "<<out<<endl;
        
        getline(ss,out);
        
        for(int i=out.length()-1;i>=0;i--){
            if(out.at(i)=='/'){
                out.erase(0,i+1);
            }
        }
//        cout<<out;
        stringstream ss2(out);

        if(out.find('?')!=string::npos ){

        getline(ss2,out,'?');
        o1<<"Method: "<<out<<endl;
        getline(ss2,out);
        }
        else {
        getline(ss2,out);
        o1<<endl;
        }
        
        
        
        
        
        o1.close();
        

        print(out,argv[2]);
    
    }
ofstream o1(argv[2],ios::app);
o1<<"====="<<endl;
        
    

return 0;
}











void print(string url,char arg[]){
   
    stringstream ss1(url);
    ofstream o1(arg,ios::app); 
    string ot,ot2;
    while(getline(ss1,ot,'=')){
    ot2.clear();
    getline(ss1,ot2,'&');
    
    if(ot2.length()>0){
        o1<<ot<<": "<<ot2<<endl;
    }
    }
    
    o1.close();
}
    
    
    
