#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    cout << "Enter first point:";
    cin.ignore(1) ;
    cin >> x1 ;
    cin.ignore(1);
    cin >> y1 ;
    cout << "Enter second point:";
    cin.ignore(3);
    cin >> x2;
    cin.ignore(1);
    cin >> y2;
    while(!(x1==0&&x2==0&&y1==0&&y2==0)) {
        cout << "Distance: " << sqrt(pow(1.0*abs(x1-x2),2)+pow(1.0*abs(y1-y2),2)); 
        cout << endl;
        cout << "Enter first point:";
        cin.ignore(100,'(') ;
        cin >> x1 ;
        cin.ignore(1);
        cin >> y1 ;
        cout << "Enter second point:";
        cin.ignore(3);
        cin >> x2;
        cin.ignore(1);
        cin >> y2;
    }    
    return 0;
}
