#include <iostream>
using namespace std;
const int MAXSZ = 100;

int main () {
    int choose;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> choose;
  while (choose!=3) {
    int len;
    char sen[MAXSZ];
    switch (choose) {
        case 1:
            cout << "Please enter sentences length: "; 
            cin >> len;
            for (int i=0; i<len; i++) {
                cin >> sen[i];
            }
            for (int i=0; i<len; i+=2) {
                cout << sen[i];
            }
            for (int i=1; i<len; i+=2) {
                cout << sen[i];
            }
            cout << endl;
            break;
        case 2:
            cout << "Please enter sentences length: "; 
            cin >> len;
            for (int i=0; i<len; i++) {
                cin >> sen[i];
            }
            for (int i=0; i<(len/2); i++) {
                cout << sen[i];
                cout << sen[i+(len/2)];
            }
            cout << endl;
            break;
        default:
            cout << "invalid input\n";
    }
    cout << endl;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> choose;
  }
    return 0;
}
