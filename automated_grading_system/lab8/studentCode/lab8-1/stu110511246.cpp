#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    while(1){
        string a,b;
        cout<<"Enter first point:";
        cin>>a;
        cout<<"Enter second point:";
        cin>>b;
        if(a=="(0,0)"&&b=="(0,0)")
        break;
        int p=a.find(",");
        int q=b.find(",");
        int x1=stoi(a.substr(1,p-1));
        int y1=stoi(a.substr(p+1,a.length()-p-1));
        int x2=stoi(b.substr(1,q-1));
        int y2=stoi(b.substr(q+1,b.length()-q-1));
        cout<<"Distance: "<<sqrt(pow(x2-x1,2)+pow(y2-y1,2))<<endl;
    }
    return 0;
}
