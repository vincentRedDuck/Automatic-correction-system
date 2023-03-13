#include<bits/stdc++.h>
using namespace std;
int main(){
while(1){
    int a,b,c,d;
    char x1,x2;
    cout<<"Enter first point:";
    cin>>x1>>a>>x1>>b>>x1;
    cout<<"Enter second point:";
    cin>>x2>>c>>x2>>d>>x2;
    if(a==c&&b==d){
        break;
    }
    cout<<"Distance: "<<pow((c-a)*(c-a)+(d-b)*(d-b),0.5)<<endl;
}
    return 0;
}
