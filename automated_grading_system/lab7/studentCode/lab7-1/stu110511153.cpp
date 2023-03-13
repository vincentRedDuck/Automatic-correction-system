#include <bits/stdc++.h>
using namespace std;
struct CARD{
    char suit;
    int value;
};

void sf(int value[],int s)
{
    for(int j=1;j<s;j++)
    {
        int key = value[j];
        int k=j-1;

        while(k>=0 && value[k]>key)
        {
            value[k+1]=value[k];
            --k;
        }
        value[k+1] = key;
    }
}
void daS(int value[],int j)
{
    for(int i=0;i<j;i++)
        cout<<"suit: Spades number: "<<value[i]<<endl;
}
void daH(int value[],int k)
{
    for(int i=0;i<k;i++)
        cout<<"suit: Heart number: "<<value[i]<<endl;
}

int main(){
    int j=0,k=0;
    int valueS[10]={0};
    int valueH[10]={0};
    CARD name[10]; 
    for(int i=1;i<=10;i++)
    {
        cout<<"#"<<i<<" "<<"card suit: ";
        cin>> name[i-1].suit;
        cout<<"#"<<i<<" "<<"card number: ";
        cin>> name[i-1].value;
        if( name[i-1].suit=='s')
            { 
                valueS[j]= name[i-1].value;
                j++;
            }
        else if( name[i-1].suit=='h')
        {
            valueH[k] = name[i-1].value;
            k++;
        }
    }

    cout<<endl<<"after sort"<<endl;
    sf(valueS,j);
    sf(valueH,k);
    daS(valueS,j); 
    daH(valueH,k);
    return 0;
}
