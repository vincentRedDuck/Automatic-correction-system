#include<iostream>
using namespace std;
#include<string>
#include<cmath>

int main() {
    string p1;
    string p2;
    cout << "Enter first point:";
    cin >> p1;
    cout << "Enter second point:";
    cin >> p2;
    while (p1!="(0,0)" or p2!="(0,0)") {
        cout << "Distance: ";
        int pos1=p1.find(",");
    /*for (int i=0 ; i < p1.length() ; i++) {
        if (p1.at(i)==',') {
            int x1p=i;
        }
    }*/
        string sx1 = p1.substr(1,pos1-1);
        int x1 = stoi(sx1);
        int pos2=p1.find(")");
        string sy1 = p1.substr(pos1+1,pos2-pos1-1);
        int y1 = stoi(sy1);

        int pos3=p2.find(",");
        string sx2 = p2.substr(1,pos3-1);
        int x2 = stoi(sx2);
        int pos4=p2.find(")");
        string sy2 = p2.substr(pos3+1,pos4-pos3-1);
        int y2 = stoi(sy2);
        double dis = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
        cout << dis << endl;

        cout << "Enter first point:";
        cin >> p1;
        cout << "Enter second point:";
        cin >> p2;
    }
}
