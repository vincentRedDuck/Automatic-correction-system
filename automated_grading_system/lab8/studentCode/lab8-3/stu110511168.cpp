#include<bits/stdc++.h>
using namespace std;

int running(){
    string s;
    cout << "Enter the sentence: ";
    getline(cin, s);
    if(s == "Stop the program")
        return 1;

    vector<string> v = {""};
    int flag = 0;
    for(auto x: s){
        if(x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z'){
            flag = 1;
            v[v.size()-1] += x;
        }

        else if(flag == 1){
            v.push_back("");
            flag = 0;
        }   
    }

    for(int i=v.size()-1; i>=0; --i)
        if(v[i] != "")
            cout << v[i] << ((i!=0)? " ": "");

    cout << "\n";

    return 0;
}

int main(){
    while(1)
        if(running())
            break;
}

