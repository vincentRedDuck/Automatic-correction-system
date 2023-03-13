#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1)
    {string s1,s2;
    cout<<"Enter first point:";
    cin>>s1;
    int a = s1.find(',');
    int b1=stoi(s1.substr(1,a-1));
    int a2=s1.length();
    int b2=stoi(s1.substr(a+1,a2-a-1));
    cout<<"Enter second point:";
    cin>>s2;
    int c = s2.find(',');
    int d1=stoi(s2.substr(1,c-1));
    int c2=s2.length();
    int d2=stoi(s2.substr(c+1,c2-c-1));
    double x=sqrt(pow(d1-b1,2)+pow(d2-b2,2));
    if(x!=0)
    {cout<<"Distance: ";
        cout<<x<<endl;
}
else
    break;
    
    
    }

    
    
    return 0;
}
