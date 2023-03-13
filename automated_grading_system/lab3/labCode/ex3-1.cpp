#include <iostream>
using namespace std;

int main() {
    cout << "Length = ";
    int L;
    while(cin >> L && L != 0) {
        int count = 0;
        while( L > 0) {
            count += L*L;
            L--;
        }
        cout << count << endl;
        cout << "Length = ";
    }
    return 0;
}