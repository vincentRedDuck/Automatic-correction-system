#include<iostream>
#include<iomanip>
using namespace std;

struct CARD
{
    char suit;
    int value;
};

void sort(CARD card [10],int length,char type);

int main()
{
    CARD spade[10];
    CARD heart[10];
    int ns=0;
    int nh=0;
    int t = 0;
    char suit;
    int value;
    while(t<=9)
    {
        cout<<"#"<<t+1<<" card suit: ";
        cin>>suit;
        cout<<"#"<<t+1<<" card number: ";
        cin>>value;
        CARD card = {suit,value};
        if (suit=='s')
        {
            spade[ns]=card;
            ns++;
        }
        else if(suit=='h')
        {
            heart[nh]=card;
            nh++;
        }
        t++;
    }

    cout<<endl<<"after sort"<<endl;

    if (ns>0)
    {
        sort(spade,ns,'s');
    }
    if (nh>0)
    {
        sort(heart,nh,'h');
    }
    
    return 0;
}

void sort(CARD card [10],int length,char type)
{
    for(int j=0;j<length;j++)
    {
        int i=j-1;
        CARD key = card[j];
        int comp=key.value;
        while((i>=0)&&(card[i].value>comp))
        {
            card[i+1]=card[i];
            i--;
        }
        card[i+1]=key;
    }

    for(int i=0;i<length;i++)
    {
        if(type=='s')
        {
            cout<<"suit: Spades number: "<<card[i].value<<endl;
        }
        else if(type=='h')
        {
            cout<<"suit: Heart number: "<<card[i].value<<endl;
        }
    }    

}

