#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Height = ";
    int height;
    while(cin >> height && height != 0) {
        for(int row = 0; row < height; row++) {
            int key = abs(row-(height-1)/2);
            for(int space = key; space > 0; space--)
                cout << " ";
            int digitLen = height-key*2;
            int mid = (digitLen-1)/2;
            int value = 0;
            for(int digit = 0; digit < digitLen; digit++) {
                if(digit <= mid)
                    value++;
                else
                    value--;
                cout << value;
            }
            cout << "\n";
        }
        cout << "Height = ";
    }
    return 0;
}