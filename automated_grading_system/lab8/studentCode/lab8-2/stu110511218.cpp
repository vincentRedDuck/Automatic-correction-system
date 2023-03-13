#include<bits/stdc++.h>
using namespace std;
int main()
{
    string message;
    int sum=0;
    while(1)
    {
    cout<<"Enter message: ";
    getline(cin,message);
    if(message=="Stop")
    break;
    for(int i=65;i<=90;i++)
    {
        sum=0;
        for(int j=0;j<message.length();j++)
        {
            if(message[j]==char(i))
            sum++;
        }
        if(sum!=0)
        cout<<char(i)<<": "<<sum<<endl;

    }
    for(int i=97;i<=122;i++)
    {
        sum=0;
        for(int j=0;j<message.length();j++)
        {
            if(message[j]==char(i))
            sum++;
        }
        if(sum!=0)
        cout<<char(i)<<": "<<sum<<endl; 
    }

    }
    return 0;
}
