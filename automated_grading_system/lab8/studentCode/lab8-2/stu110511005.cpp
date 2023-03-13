#include<iostream>
using namespace std;

int main() {
    cout << "Enter message: ";
    string str;
    getline(cin, str);
    while (str!="Stop") {
        int arr[52]={0};
        for (int i=0 ; i<str.length() ; i++) {
            char st = str[i];
            int asstr = int(st);
            if (asstr >=65 and asstr<=90)  {
                arr[asstr-65]++;
            }
            else if (asstr >=97 and asstr <=122) {
                arr[asstr-71]++;
            }
        }
        for (int i=0 ; i<52 ; i++) {
            if (arr[i] != 0) {
                if (i>=0 and i<=25) {
                    cout << char(i+65) << ": " << arr[i] << endl;
                }
                else if (i>=26 and i<=51) {
                    cout << char(i+71) << ": " << arr[i] << endl;
                }
            }
        }
        cout << "Enter message: ";
        getline(cin, str);
    }
}
