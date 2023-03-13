#include<bits/stdc++.h> 
using namespace std;

struct dot{int x;int y;};

void entdot(dot& A)
{
    cin.ignore(1,'(');
    cin>>A.x;
    cin.ignore(1,',');
    cin>>A.y;
    cin.ignore(2,'\n');
    return ;
}

int main()
{
    dot A,B;
    while(1)
    {
        cout<<"Enter first point:";
        entdot(A);
        cout<<"Enter second point:";
        entdot(B);
        if(A.x==0&&A.y==0&&B.x==0&&B.y==0)
        break;
        cout<<"Distance: "<<sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))<<endl;
    
    }

}
