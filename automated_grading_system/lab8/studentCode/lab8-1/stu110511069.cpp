#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int N;
    cout<<"Enter first point:";
    cin.ignore(1);
    int a,b;
    cin>>a;

   
    cin.ignore(1);
    cin>>b;    
    cin.ignore(1);

    cout<<"Enter second point:";
    cin.ignore(2);
    int c,d;
    cin>>c;
    cin.ignore(1);
    cin>>d;
    cin.ignore(1);
    while(a!=0||b!=0||c!=0||d!=0){
         cout<<"Distance: "<<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;
   
         cout<<"Enter first point:";
        cin.ignore(2);

        cin>>a;
        cin.ignore(1);
        cin>>b;
        cin.ignore(1);

        cout<<"Enter second point:";
        cin.ignore(2);

        cin>>c;
        cin.ignore(1);
        cin>>d;  
        cin.ignore(1);
     
    }   
    return 0;
}
