// #include <iostream>
// #include <string>
// #include <cstring>
// #include <cmath>
// using namespace std;

// int main(){

//     while(1){
//         string s1, s2;
//         int x1, x2, y1, y2;
//         int p1, p2;
        
//         cout << "Enter first point:";
//         getline(cin, s1);
//         p1 = s1.find("(");
//         p2 = s1.find(",");
//         x1 = atoi((s1.substr(p1+1, p2-p1)).c_str());

//         p1 = s1.find(")");
//         y1 = atoi((s1.substr(p2+1, p1-p2)).c_str());

//         cout << "Enter second point:";
//         getline(cin, s2);
//         p1 = s2.find("(");
//         p2 = s2.find(",");
//         x2 = atoi((s2.substr(p1+1, p2-p1)).c_str());

//         p1 = s2.find(")");
//         y2 = atoi((s2.substr(p2+1, p1-p2)).c_str());

        // if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        //     break;
        // else
        //     cout << "Distance: " << sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    while(1){
        string s, tmp;
        stringstream ss;
        int x1, x2, y1, y2;

        cout << "Enter first point:";
        getline(cin, s);
        for(int i = 0 ; i < s.length() ; i++)
            if(s[i] == '(' || s[i] == ',' || s[i] == ')')
                s[i] = ' ';
        ss << s;
        ss >> tmp; x1 = stoi(tmp);
        ss >> tmp; y1 = stoi(tmp);

        cout << "Enter second point:";
        getline(cin, s);
        for(int i = 0 ; i < s.length() ; i++)
            if(s[i] == '(' || s[i] == ',' || s[i] == ')')
                s[i] = ' ';
        ss << s;
        ss >> tmp; x2 = stoi(tmp);
        ss >> tmp; y2 = stoi(tmp);

        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;
        else
            cout << "Distance: " << sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) << endl;
    }
    return 0;
}