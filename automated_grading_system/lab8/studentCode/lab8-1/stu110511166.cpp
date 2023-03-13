#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    string f;
    string s;
    while(1){
        cout << "Enter first point:";
        cin >> f;
        cout << "Enter second point:";
        cin >> s;
        if(f=="(0,0)"&&s=="(0,0)")
            break;
        else{
            int p = f.find(',');
            int q = s.find(',');
            int a,b,c,d;
            a = stoi(f.substr(1,p-1));
            b = stoi(f.substr(p+1,f.length()-p-1));
            c = stoi(s.substr(1,q-1));
            d = stoi(s.substr(q+1,s.length()-q-1));
            cout << "Distance: " << sqrt((a-c)*(a-c)+(b-d)*(b-d)) << endl;
        }
        

    }
    return 0;
}
