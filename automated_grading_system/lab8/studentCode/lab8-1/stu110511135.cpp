#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    string a,b;
    cout << "Enter first point:";
    cin >> a;
    cout << "Enter second point:";
    cin >> b;
    int d;
    int astart = a.find(',');
    int aend = a.find(')');
    int bstart = b.find(',');
    int bend = b.find(')');
    int x1 = stoi(a.substr(1,astart-1));
    int y1 = stoi(a.substr(astart+1,aend-1));
    int x2 = stoi(b.substr(1,bstart-1));
    int y2 = stoi(b.substr(bstart+1,bend-1));
    while(x1!=0||y1!=0||x2!=0||y2!=0){
        cout << "Distance: ";
        double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        cout << d << endl;
        cout << "Enter first point:";
        cin >> a;
        cout << "Enter second point:";
        cin >> b;
        astart = a.find(',');
        aend = a.find(')');
        bstart = b.find(',');
        bend = b.find(')');
        x1 = stoi(a.substr(1,astart-1));
        y1 = stoi(a.substr(astart+1,aend-1));
        x2 = stoi(b.substr(1,bstart-1));
        y2 = stoi(b.substr(bstart+1,bend-1));
    }


return 0;
}
