#include <iostream>
#include <string>
using namespace std;
const int MAX = 52; 
int main () {
    cout << "Enter message: ";
    string str;
    getline(cin, str);
    while (str!="Stop") {
        int arr[MAX] = {0};
        for (int i=0; i<str.length(); i++) {
            if (int(str[i])>=65 && int(str[i])<=90) {
                int x = str[i] - 65;
                arr[x]++;
            }
            else if (int(str[i])>=97 && int(str[i])<=122) {
                int x = str[i] - 71;
                arr[x]++;
            }
        }
        
        for (int j=0; j<MAX; j++) {
            char c;
            if (arr[j]!=0) {
                if (j<26) {
                    c = char(j+65);
                }
                else {
                    c = char(j+71);
                }
                cout << c << ": " << arr[j] << endl;
            }  
        }
        cout << "Enter message: ";
        getline(cin, str);
    }

    return 0;
}
