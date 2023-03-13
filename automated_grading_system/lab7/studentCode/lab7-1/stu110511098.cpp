#include<iostream>
using namespace std;
struct CARD{
    char suit;
    int value;
};
const int MAX_NUM = 10;

int main(){
    int sn=0; int hn=0;
    
    CARD card[MAX_NUM];
    int sprade[10],heart[10];
    for(int i=1;i<=MAX_NUM;i++){
        cout<<"#"<<i<<" card suit: ";
        cin>>card[i-1].suit;
        cout<<"#"<<i<<" card number: ";
        cin>>card[i-1].value;
    }
    cout<<"\nafter sort"<<endl;
    for(int j=0;j<MAX_NUM;j++){
        if(card[j].suit=='s'){
            sprade[sn]=card[j].value;
            sn++;
        }
        else{
            heart[hn]=card[j].value;
            hn++;
        }
    }
    for(int i=1;i<sn;i++){
        int key = sprade[i];
        int j=i-1;

        while (j>=0&&sprade[j]>key){
            sprade[j+1] = sprade[j];
            --j;
        }
        sprade[j+1] = key;
    }
    for(int i=1;i<hn;i++){    
        int key = heart[i];
        int j=i-1;
 
        while (j>=0&&heart[j]>key){
            heart[j+1] = heart[j];
            --j;
        }
        heart[j+1] = key;
    }
    for(int i=0;i<sn;i++){
        cout<<"suit: Spade number: "<<sprade[i]<<endl;
    }
    for(int i=0;i<hn;i++){
        cout<<"suit: Heart number: "<<heart[i]<<endl;
    }
    return 0;
}
