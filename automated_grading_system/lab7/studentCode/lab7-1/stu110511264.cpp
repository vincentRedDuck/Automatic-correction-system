#include<bits/stdc++.h>
using namespace std;
struct CARD{
    char suit;
    int value;
};
void f(CARD card[],int num){
    for(int i=0;i<num;i++){
        cout<<"#"<<i+1<<" card suit: ";
        cin>>card[i].suit;
        cout<<"#"<<i+1<<" card number: ";
        cin>>card[i].value;
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(card[i].value<card[j].value){
                CARD temp=card[j];
                card[j]=card[i];
                card[i]=temp;
            }
        }
    }
    cout<<"\n"<<"after sort"<<"\n";
    for(int i=0;i<num;i++){
        if(card[i].suit=='s'){
            cout<<"suit: Spades number: "<<card[i].value<<endl;
            
        }
    }
    for(int i=0;i<num;i++){
        if(card[i].suit=='h'){
            cout<<"suit: Heart number: "<<card[i].value<<endl;
        }
    }
}
int main(){
    int numcard=10;
    CARD card[numcard];
    f(card,numcard);
    return 0;
}
