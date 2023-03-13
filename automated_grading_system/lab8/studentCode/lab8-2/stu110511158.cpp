#include<iostream>
#include<string>
using namespace std;

int main() {
    while (1) {
        string x;
        int k,s;
        cout << "Enter message: ";
        getline(cin,x);
        if (x == "Stop")
            break; 
        for (int k=65;k<=90;k++) {
            s =0;
            for (int i=0;i<x.length();i++) {
                if (x[i]==char(k))
                    s++; 
            }
        
            if (s!=0)
                cout << char(k) << ": " << s << endl;
        }
        for (int k=97;k<=122;k++) {
            int s =0;
            for (int i=0;i<x.length();i++) {
                if (x[i]==char(k))
                    s++;
            }
            if (s!=0)
                cout << char(k) << ": " << s << endl;
        }
    } 
    return 0;
}
