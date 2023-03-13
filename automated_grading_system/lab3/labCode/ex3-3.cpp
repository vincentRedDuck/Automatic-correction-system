#include <iostream>
using namespace std;

int main() {
    cout << "Height = ";
    int height;
    while(cin >> height && height != 0) {
        for(int row = 0; row < height; row++) {
            for(int space = height - row - 1; space > 0; space--)
                cout << " ";
            int before_A_ASCII = 64;
            int increment = 0;
            for(int alpha = 0; alpha <= row; alpha++) {
                if(alpha == 0 && row != 0) {
                    increment = 1;
                    cout << char(before_A_ASCII + increment) << "*";
                } else if(alpha == row) {
                    increment = 1;
                    cout << char(before_A_ASCII + increment);
                } else {
                    increment = increment * (row-alpha+1)/alpha;  //Pascal triangle's property
                    cout << char(before_A_ASCII + increment) << "*";
                }
            }
            cout << endl;
        }
        cout << "Height = ";
    }
    return 0;
}
