#include <iostream>
#include <string>
#include <ctype.h>
#include <cmath>
using namespace std;
int main(){
    string t="",a,b="";
    cout << "Enter first point:";
    getline(cin,a);
    b = a.substr(1,a.find(",")-1);
    /*for (int i = 0; i<a.find(","); i++){
        if(isdigit(a[i])){
            t = a[i];
            b = b+t;
        }
    }*/
    int aa = stoi(b);
    //cout << aa << ",";
    t = a.substr(a.find(",")+1,a.find(")")-a.find(","));
    //b = "";
    /*for (int i = a.find(","); i<a.find(")"); i++){
        if(isdigit(a[i])){
            t = a[i];
            b = b+t;
        }
    }*/
    int bb = stoi(t);
    //cout << bb;

    string m="",x,y="";
    cout << "Enter second point:";
    getline(cin,x);
    y = x.substr(1,x.find(",")-1);
    /*for (int i = x.find("("); i<x.find(","); i++){
        if(isdigit(x[i])){
            m = x[i];
            y = y+m;
        }
    }*/
    int xx = stoi(y);
    //cout << xx << ",";
    y = "";
    m = x.substr(x.find(",")+1,x.find(")")-x.find(","));
    /*for (int i = x.find(","); i<x.find(")"); i++){
        if(isdigit(x[i])){
            m = x[i];
            y = y+m;
        }
    }*/
    int yy = stoi(m);
    //cout << yy;
    while(!(xx==0 &&yy==0 &&aa==0 &&bb==0)){
    double k;
    //cout<<aa<<" "<<xx<<" "<<bb<<" "<<yy<<endl;
    k = sqrt(pow((aa-xx),2)+pow((bb-yy),2));
    cout << "Distance: " << k << endl;
    cout << "Enter first point:";
    getline(cin,a);
    b = "";
    b = a.substr(1,a.find(",")-1);
    /*for (int i = 0; i<a.find(","); i++){
        if(isdigit(a[i])){
            t = a[i];
            b = b+t;
        }
    }*/
    aa = stoi(b);
    //cout << aa << ",";
    //b = "";
    t = a.substr(a.find(",")+1,a.find(")")-a.find(","));
    /*for (int i = a.find(","); i<a.find(")"); i++){
        if(isdigit(a[i])){
            t = a[i];
            b = b+t;
        }
    }*/
    bb = stoi(t);
    //cout << bb;

    y="";
    cout << "Enter second point:";
    getline(cin,x);
    y = x.substr(1,x.find(",")-1);
    /*for (int i = x.find("("); i<x.find(","); i++){
        if(isdigit(x[i])){
            m = x[i];
            y = y+m;
        }
    }*/
    xx = stoi(y);
    //cout << xx << ",";
    //y = "";
    /*for (int i = x.find(","); i<x.find(")"); i++){
        if(isdigit(x[i])){
            m = x[i];
            y = y+m;
        }
    }*/
    m = x.substr(x.find(",")+1,x.find(")")-x.find(","));
    yy = stoi(m);
    //cout<<yy<<endl;
    }
    return 0;
}
