#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main () {
    double d = 0;
        cout << "Enter first point:";
        string p1;
        getline(cin, p1);
        int x1 = p1.find(",");
        string spx1 = p1.substr(1,x1-1);
        int px1 = stoi(spx1);
    
        int y1 = p1.find(")") - x1 - 1;
        string spy1 = p1.substr(x1+1,y1);
        int py1 = stoi(spy1);
        
        cout << "Enter second point:";
        string p2;
        getline(cin, p2);
        int x2 = p2.find(",");
        string spx2 = p2.substr(1,x2-1);
        int px2 = stoi(spx2);
    
        int y2 = p2.find(")") - x2 - 1;
        string spy2 = p2.substr(x2+1,y2);
        int py2 = stoi(spy2);
    while ((px1!=0)||(px2!=0)||(py1!=0)||(py2!=0)) {
        
        d = sqrt(((px1)-(px2))*((px1)-(px2)) + ((py1-py2)*(py1-py2)));
        cout << "Distance: " << d << endl;
        cout << "Enter first point:";
        string p1;
        getline(cin, p1);
        x1 = p1.find(",");
        string spx1 = p1.substr(1,x1-1);
        px1 = stoi(spx1);
    
        y1 = p1.find(")") - x1 - 1;
        string spy1 = p1.substr(x1+1,y1);
        py1 = stoi(spy1);
        
        cout << "Enter second point:";
        string p2;
        getline(cin, p2);
        x2 = p2.find(",");
        string spx2 = p2.substr(1,x2-1);
        px2 = stoi(spx2);
    
        y2 = p2.find(")") - x2 - 1;
        string spy2 = p2.substr(x2+1,y2);
        py2 = stoi(spy2);
    }

    return 0;
}
