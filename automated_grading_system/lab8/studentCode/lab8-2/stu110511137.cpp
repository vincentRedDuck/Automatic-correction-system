#include<iostream>
#include<string>
using namespace std;

void find (const string s) {
    int n = 0, count = 0;
    for (int i=0; i<26; i++) {
        n = 0;
        count = 0;
        while (s[n]!='\0') {
            if (s[n] == char(i+'A')) {
                count++;
            }
            n++;
        }
        if (count!=0)
            cout << char (i+'A') << ": " << count << endl;
    }
    for (int i=0; i<26; i++) {
        n = 0;
        count = 0;
        while (s[n]) {
            if (s[n] == char(i+'a')) {
                count++;
            }
            n++;
        }
        if (count!=0)
            cout << char (i+'a') << ": " << count << endl;
    }
}

int main () {
    string s;
    cout << "Enter message: ";
    getline(cin,s);
    while (s != "Stop") {
        find(s);
        cout << "Enter message: ";
        getline(cin,s);
    }
    return 0;
}
