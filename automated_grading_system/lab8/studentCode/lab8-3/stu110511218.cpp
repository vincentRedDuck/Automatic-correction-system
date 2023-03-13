#include<bits/stdc++.h>
using namespace std;

void print(string& sen,int i)
{
    int j=i;
    bool space=1;
    for(;j<sen.length();j++)
    {
        if((sen[j]>=97&&sen[j]<=122)||(sen[j]>=65&&sen[j]<=90));
        else
        {print(sen,j+1);break;}
    }
    if(i==j)
    space=0;
    for(;i<j;i++)
    cout<<sen[i];
    if(space)
    cout<<" ";
}


int main()
{
    string sen;
    while(1)
    {
    cout<<"Enter the sentence: ";
    getline(cin,sen);
    if(sen=="Stop the program")
    break;
    print(sen,0);
    cout<<endl;
    }
}
