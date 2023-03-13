#include<bits/stdc++.h>
using namespace std;

void en(){
    cout << "Please enter sentences length: ";
    int n;
    cin >> n;
    char c[n];
    cin >> c;
    string s;
    for(int i=0; i<(n+1)/2; ++i)
        s += c[2*i];
    
    for(int i=0; i<(n+1)/2; ++i)
        s += c[2*i+1];

    cout << s << "\n\n";
}

void de(){
    cout << "Please enter sentences length: ";
    int n;
    cin >> n;
    char c[n];
    cin >> c;
    string s;
    for(int i=0; i<n; ++i){
        if(i%2 == 0)
            s += c[i/2];

        else
            s += c[i/2+(n+1)/2];
    }

    cout << s << "\n\n";
}

int main(){
    while(1){
        cout << "1: encoder 2: decoder 3: quit: ";
        int n;
        cin >> n;
        if(n == 3)
            break;

        else if(n == 1)
            en();
        
        else if(n == 2)
            de();

        else
            cout << "invalid input\n\n";
    }
}

