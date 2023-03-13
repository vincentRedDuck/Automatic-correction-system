#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

struct coordinate{
    int x;
    int y;
};

double distance(string x,string y){
    int pos;
    int len;
    coordinate a;
    coordinate b;

    pos = x.find(",");
    len = x.length();
    string temp = x;

    temp.erase(0,1);
    temp.erase(pos-1,(len-pos));
    a.x = stoi(temp);
    temp = x;
    temp.erase(0,pos+1);
    temp.erase((len-pos-2),1);
    a.y = stoi(temp);

    pos = y.find(",");
    len = y.length();
    temp = y;

    temp.erase(0,1);
    temp.erase(pos-1,(len-pos));
    b.x = stoi(temp);
    temp = y;
    temp.erase(0,pos+1);
    temp.erase((len-pos-2),1);
    b.y = stoi(temp);

    return sqrt(pow((a.x-b.x),2.0)+pow((a.y-b.y),2.0));
}

int main(){
    string x;
    string y;
while(1){
    cout << "Enter first point:";
    cin >> x;
    cout << "Enter second point:";
    cin >> y;
    string key ="(0,0)";
    if(x == key&&y == key){
        break;
    }
    else{
        cout << "Distance: "<< distance(x,y) << endl;
    }}
return 0;
}

