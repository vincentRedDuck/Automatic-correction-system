#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
    while(1){
        stringstream ss;
        string s, ans, tmp;
        cout << "Enter the sentence: ";
        getline(cin, s);
        if(!s.compare("Stop the program"))
            break;
        ans = "";
        ss << s;
        while(ss >> tmp){
            if(!ans.compare(""))
                ans += tmp;
            else
                ans = tmp + " " + ans;
        }
        cout << ans << endl;
    }
    return 0;
}