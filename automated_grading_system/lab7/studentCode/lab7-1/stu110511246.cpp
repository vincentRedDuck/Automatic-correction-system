#include<iostream>
#include<algorithm>
using namespace std;
struct CARD {
    char suit;
    int value;
};
int main()
{
    CARD card[10];
    for(int i=0; i<10; i++)
    {
        cout<<"#"<<i+1<<" card suit: ";
        cin>>card[i].suit;
        cout<<"#"<<i+1<<" card number: ";
        cin>>card[i].value;
    }
    cout<<"\nafter sort"<<endl;
    int snum=0,hnum=0;
    for(int i=0; i<10; i++)
    {
        if(card[i].suit=='s')
            snum++;
        else
            hnum++;
    }
    int sarray[snum],harray[hnum];
    int j=0;
    for(int i=0; i<10; i++)
    {
        
        if(card[i].suit=='s'){
            sarray[j]=card[i].value;
            j++;
        }
        
        
    }
    j=0;
    for(int i=0; i<10; i++)
    {
        
        if(card[i].suit=='h'){
            harray[j]=card[i].value;
            j++;
        }
    }
        sort(sarray,sarray+snum);
        sort(harray,harray+hnum);
        for(int i=0; i<snum; i++)
        {
            cout<<"suit: Spades number: "<<sarray[i]<<endl;
        }
        for(int i=0; i<hnum; i++)
        {
            cout<<"suit: Heart number: "<<harray[i]<<endl;
        }
        return 0;
    
}

