#include<iostream>
#include<cmath>
using namespace std;
int main () {
    while(true) {
        cout << "Enter first point:";
        int x1,x2,y1,y2;
        char a,b,c,d,e,f;
        cin >> a >> x1 >> b >> y1 >> c;
        cout << "Enter second point:";
        cin >> d >> x2 >> e >> y2 >> f;
        if((x1==0)&&(y1==0)&&(x2==0)&&(y2==0)) {
            break;
        }
        cout << "Distance: ";
        cout << sqrt(pow((x2-x1),2)+pow((y2-y1),2)) << endl;
    }

    return 0;
}
