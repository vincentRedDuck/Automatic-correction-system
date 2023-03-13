#include<iostream>
#include<string>
using namespace std;

int main() {
    string a;
    while(1) {
        cout << "Enter message: ";
        getline(cin , a);
        if(a == "Stop")
            break;
        else {
            int X[26]= {0};
            int x[26]= {0};
            for(int i = 0; i < a.length(); i++) {
                if(int(a[i])<=90)
                    X[a[i]-'A']++;
                else
                    x[a[i]-'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(X[i]>0)
                    cout << char(i+65) << ": " << X[i] << endl;
            }
            for(int i =0; i < 26; i++) {
                if(x[i]>0)
                    cout << char(i+97) << ": " << x[i] << endl;
            }
        }
    }

    return 0;
}
