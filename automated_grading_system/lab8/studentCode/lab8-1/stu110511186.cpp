#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
  string fpoi;
  string spoi;
  do{
    int x1,y1,x2,y2 ;
    double dis;
    
    cout <<"Enter first point:";
    cin >> fpoi;
    
    string temp = fpoi;
    temp.erase(0,temp.find("(")+1);
    temp.erase(temp.find(","),temp.find(")"));
    x1 = stoi(temp);
    
    temp = fpoi;
    temp.erase(0,temp.find(",")+1);
    temp.erase(temp.find(")"),temp.find(")")+1);
    y1 = stoi(temp);

    cout <<"Enter second point:";
    cin >> spoi;
    if((fpoi =="(0,0)")&&(spoi == "(0,0)")) break;    
    
       
    temp = spoi;
    temp.erase(0,temp.find("(")+1);
    temp.erase(temp.find(","),temp.find(")"));
    x2 = stoi(temp);
    
    temp = spoi;
    temp.erase(0,temp.find(",")+1);
    temp.erase(temp.find(")"),temp.find(")")+1);
    y2 = stoi(temp);
    
   // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    cout <<"Distance: "<< dis << endl;
    }while(!((fpoi =="(0,0)")&&(spoi == "(0,0)")));
    
   // cout <<"Enter first point:";
   // cin >> fpoi;

   // cout <<"Enter second point:";
   // cin >> spoi;
    
}
 
