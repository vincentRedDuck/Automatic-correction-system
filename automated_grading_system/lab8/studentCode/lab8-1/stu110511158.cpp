#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
    string x,y;
    double d;
    while (1) {
        cout << "Enter first point:";
        getline(cin,x);
        cout << "Enter second point:";
        getline(cin,y);
        int x1 =stoi(x.substr(1,x.find(",")-1));
        int y1 =stoi(x.substr(x.find(",")+1,(x.find(")")-x.find(","))-1));
        int x2 =stoi(y.substr(1,y.find(",")-1));
        int y2 =stoi(y.substr(y.find(",")+1,(y.find(")")-y.find(","))-1));
        if (x1==0&&x2==0&&y1==0&&y2==0) 
            break;
        d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        cout << "Distance: " << d << endl;
    }
    return 0;
}
