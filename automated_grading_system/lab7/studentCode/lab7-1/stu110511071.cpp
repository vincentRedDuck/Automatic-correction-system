#include<iostream>
using namespace std;
struct CARD{
    char suit;
    int value;
};
int main(){
    CARD card[10];
        for (int i=0;i<10;i++){
            cout<<"#"<<i+1<<" card suit: ";
            cin>>card[i].suit;
            cout<<"#"<<i+1<<" card number: ";
            cin>>card[i].value;
        }
    CARD spade[10];
    CARD heart[10];

    CARD key;
    int s=0,h=0;
        for(int i=0;i<10;i++){
            if (card[i].suit=='s'){
                spade[s]=card[i];
                s++;
            }
            else if (card[i].suit=='h'){
                heart[h]=card[i];
                h++;
            }
        }
/*    sort (spade[10],s);
    sort (heart[10],h);*/
        for (int i=1;i<s;i++){
            key=spade[i];
            for (int j=0;j<i;j++){
                if (key.value < spade[i-1-j].value){
                    spade[i-j]=spade[i-j-1];
                    spade[i-j-1]=key;
                }
            }
        }
        for (int i=1;i<h;i++){
            key=heart[i];
            for (int j=0;j<i;j++){
                if (key.value < heart[i-1-j].value){
                    heart[i-j]=heart[i-j-1];
                    heart[i-j-1]=key;
                }
            }
        }

    cout<<endl<<"after sort"<<endl;

    for (int i=0;i<s;i++)
        cout<<"suit: Spades number: "<<spade[i].value<<endl;
    for (int i=0;i<h;i++)
        cout<<"suit: Heart number: "<<heart[i].value<<endl;
        
    return 0;
}
/*
void sort(CARD& a[10],int b){
    CARD key;
        for (int i=1;i<b;i++){
            key=a[i];
            for (int j=0;j<i;j++){
                if (key.value< a[i-1-j].value)
                    a[i-j]=a[i-j-1];
                else
                    a[i-j-1]=key;

            }
         }
    return;
}
*/
