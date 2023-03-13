#include<iostream>
using namespace std;

int main(){
    int n,l;
    char code[100];
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> n;
    while (n!=3) {
        if (n==1) {
            cout << "Please enter sentences length: ";
            cin >> l;
            for (int i=0;i<l;i++) 
                cin >> code[i];
            for (int i=0;i<l;i++) {
                if (i%2==0)
                    cout << code[i];
            } 
            for (int i=0;i<l;i++) {
                if (i%2==1)
                    cout << code[i];
            }
            cout << endl << endl;
        }
        else if (n==2) {
            cout << "Please enter sentences length: ";
            cin >> l;
            for (int i=0;i<l;i++)
                cin >> code[i];
            for (int i=0;i<l/2;i++) {
                cout << code[i];
                cout << code[i+l/2];
            }
            cout << endl << endl;
        }
        else
            cout << "invalid input" << endl;
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> n;
    }
    return 0;
}
