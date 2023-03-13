#include<bits/stdc++.h>
using namespace std;

int running(){
    string s;
    cout << "Enter message: ";
    getline(cin, s);
    if(s == "Stop")
        return 1;

    int up[26] = {0}, low[26] = {0};
    for(auto x: s){
        if((int)x >= int('A') && (int)x <= int('Z'))
            ++up[int(x)-int('A')];

        else if((int)x >= int('a') && (int)x <= int('z'))
            ++low[int(x)-int('a')];
    }

    for(int i=0; i<26; ++i)
        if(up[i] != 0)
            cout << char(i+int('A')) << ": " << up[i] << "\n";

    for(int i=0; i<26; ++i)
        if(low[i] != 0)
            cout << char(i+int('a')) << ": " << low[i] << "\n";

    return 0;
}

int main(){
    while(1)
        if(running())
            break;
}

