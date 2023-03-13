#include <iostream>
using namespace std;

const int MAX_CARD = 10;

struct Card
{
    char suit;
    int number;
};

bool biggerNumber(Card card1, Card card2)
{
    if(card1.number>card2.number)
        return true;
    else
        return false;
}

void swap(Card &card1, Card &card2)
{
    Card cardTemp = card1;
    card1 = card2;
    card2 = cardTemp;
}

int main()
{
    Card card_black[MAX_CARD];
    Card card_red[MAX_CARD];
    int numBlackCard = 0;
    int numRedCard = 0;
    
    for(int i =0; i<MAX_CARD; i++)
    {
        Card card;
        cout<<"#"<<i+1<<" card suit: ";
        cin>>card.suit;
        cout<<"#"<<i+1<<" card number: ";
        cin>>card.number;

        
        
        if(card.suit == 'b')
            card_black[numBlackCard++] = card;
        else
            card_red[numRedCard++] = card;
            
    }

    for(int i =0; i<numBlackCard-1; i++)
        for(int j=i+1; j<numBlackCard; j++)
            if(biggerNumber(card_black[i],card_black[j]))
                swap(card_black[i],card_black[j]);

    for(int i =0; i<numRedCard-1; i++)
        for(int j=i+1; j<numRedCard; j++)
            if(biggerNumber(card_red[i],card_red[j]))
                swap(card_red[i],card_red[j]);
    
    cout<<"\nafter sort"<<endl;
    for(int i =0; i<numBlackCard; i++)
        cout<<"suit: Spares"<<" number: "<<card_black[i].number<<endl;
    for(int i =0; i<numRedCard; i++)
        cout<<"suit: Heart"<<" number: "<<card_red[i].number<<endl;        

    return 0;
}
