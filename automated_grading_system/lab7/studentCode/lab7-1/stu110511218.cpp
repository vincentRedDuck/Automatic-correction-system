#include<iostream>
using namespace std;

struct card{int num; char suit;};

int main()
{
    card arr[10];
    for(int i=0;i<10;i++)
    {
        cout<<'#'<<i+1<<" card suit: ";
        cin>>arr[i].suit;
        cout<<'#'<<i+1<<" card number: ";
        cin>>arr[i].num;
    }
    for(int i=1;i<10;i++)
    {
        card key=arr[i];
        bool z=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j].suit<key.suit)
            {arr[j+1]=arr[j];}
            else if(arr[j].suit>key.suit)
            {arr[j+1]=key;z=1;break;}
            else
            {
                if(arr[j].num>key.num)
                arr[j+1]=arr[j];
                else
                {arr[j+1]=key;z=1;break;}
            }
            
        }
        if(z==0)
        arr[0]=key;
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"suit: "<<(arr[i].suit=='s'?"Spades":"Heart")<<" number: "<<arr[i].num<<endl;
    }


}
