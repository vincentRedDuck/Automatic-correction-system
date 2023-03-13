#include <iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
}card[11];


int main(){
    char suit;
    int value;

    for(int i = 1 ; i <= 10 ; i++){
        cout<<"#"<<i<<" card suit: ";
        cin>>suit;
        
        cout<<"#"<<i<<" card number: ";
        cin>>value;
        int idx = i;
        for( int j = 1 ; j < i ; j++ ){
            if( suit == card[j].suit ){               //hh ss
                if( value < card[j].value){
                    idx = j;
                    break;
                }
            }
            else if( suit > card[j].suit ){              //sh
                idx = j;
                break;
            }
            else                                    //hs
                continue;
        }
        for(int j = i ; j >= idx ; j--){
            if(idx == j){
                card[j].suit = suit;
                card[j].value = value;
            }
            else{
                card[j].suit = card[j-1].suit;
                card[j].value = card[j-1].value;
            }
        }
    }

    cout<<"\nafter sort\n";
    for(int i = 1 ; i < 11 ; i++)
        cout<<"suit: "<<(card[i].suit == 's'? "Spades " : "Heart ")<<"number: "<<card[i].value<<endl;

    return 0;
}