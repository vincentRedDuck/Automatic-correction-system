#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
int main(){
    while(1){
        string p1,p2;
        int ax,ay,bx,by;

        cout<<"Enter first point:";
        cin>>p1;
        cout<<"Enter second point:";
        cin>>p2;
        if(p1=="(0,0)"&&p2=="(0,0)")
            break;

        for(int i=0;i<p1.length();i++){
            if(p1[i]==','){
                ax=stoi(p1.substr(1,i-1));
                ay=stoi(p1.substr(i+1,p1.length()-i-2));
            }
        }

        for(int i=0;i<p2.length();i++){
            if(p2[i]==','){
                bx=stoi(p2.substr(1,i-1));
                by=stoi(p2.substr(i+1,p2.length()-i-2));
            }
        }
        cout<<"Distance: "<<sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay))<<endl;
    }
    return 0;
}
