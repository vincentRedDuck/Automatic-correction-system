
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int main() {
  while(1){  
    string s1, s2;
    int a, b;
    cout << "Enter first point:";
    cin >> s1;
    cout << "Enter second point:";
    cin >> s2;
    a = s1.find(",");
    b = s2.find(",");
    int p1x = stoi( s1.substr(1, a - 1) );
    int p1y = stoi( s1.substr(a + 1, s1.length() - a) );
    int p2x = stoi( s2.substr(1, b - 1) );
    int p2y = stoi( s2.substr(b + 1, s2.length() - a) );
    double d = sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
    if(d == 0){
        break;
    }
    cout << "Distance: " << d << endl;
  }
}


