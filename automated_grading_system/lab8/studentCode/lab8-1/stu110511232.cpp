#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

bool veri(string p1,string p2)
{
    if((p1=="(0,0)")&&(p2=="(0,0)"))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int x(string p)
{
    int max=sizeof(p);
    int out=0;
    int sign=1;    

    for(int i=1;i<max;i++)
    {
        if(isdigit(p[i]))
        {
            out*=10;
            char ch=p[i];
            out+=(int)ch-48;
        }
        else if(p[i]=='-')
        {
            sign=-1;
        }
        else if(p[i]==',')
        {
            break;
        }
    }
    
    return out*sign;
}

int y(string p)
{
    int max=sizeof(p);
    int out=0;
    int i_0=p.find(",");
    int sign=1;    

    for(int i=i_0;i<max;i++)
    {
        if(isdigit(p[i]))
        {
            out*=10;
            char ch=p[i];
            out+=(int)ch-48;
        }
        else if(p[i]=='-')
        {
            sign=-1;
        }
        else if(p[i]==')')
        {
            break;
        }
    }
    return out*sign;
}

int main()
{
    string p1;
    string p2;
    cout<<"Enter first point:";
    cin>>p1;
    cout<<"Enter second point:";
    cin>>p2;


    while(veri(p1,p2))
    {
        int x1,x2,y1,y2;
        x1=x(p1);
        x2=x(p2);
        y1=y(p1);
        y2=y(p2);

        double d =pow((x1-x2),2)+pow((y1-y2),2);
        d=pow(d,0.5);        
        cout<<"Distance: "<<d<<endl;

        cout<<"Enter first point:";
        cin>>p1;
        cout<<"Enter second point:";
        cin>>p2;
    }

    return 0;
}
