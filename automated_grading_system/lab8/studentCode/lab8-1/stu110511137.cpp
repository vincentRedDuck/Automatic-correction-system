#include<iostream>
#include<cmath>
using namespace std;

void input (char& c, int& x, int& y) {
    cin >> c;
    cin >> x;
    cin >> c;
    cin >> y;
    cin >> c;
}

int main () {
    char c;
    int x1, y1, x2, y2;
    cout << "Enter first point:";
    input(c, x1, y1);
    cout << "Enter second point:";
    input(c, x2, y2);
    while (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0) {
        cout <<  "Distance: " << sqrt(pow((x2-x1),2)+pow((y2-y1),2)) << endl;
        cout << "Enter first point:";
        input(c, x1, y1);
        cout << "Enter second point:";
        input(c, x2, y2);
    }
    return 0;
}
