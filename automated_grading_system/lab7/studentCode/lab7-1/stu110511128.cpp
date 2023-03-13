#include<iostream>
#include<vector>
using namespace std;
int main()
{
    struct CARD
    {
        char suit;
        int value;
    };
    CARD card[10];
    for(int i=1; i<=10; i++)
    {
        cout << "#"<< i << " card suit: ";
        cin >> card[i-1].suit;
        cout << "#"<< i << " card number: ";
        cin >> card[i-1].value;

    }
    cout << endl;
    cout <<"after sort"<< endl;
    for(int i=0; i<10; i++)
        for(int j=i; j<10 ; j++)
        {
            if(card[j-1].value>=card[j].value)
            {
                CARD num;
                num = card[j-1];
                card[j-1]=card[j];
                num = card[j];
            }

        }
    for(int i=0; i<10 ; i++)
    {
        if(card[i].suit=='s')
        {
            cout << "suit: Spades number: " << card[i].value<<endl;
        }
        else
        {
            continue;
        }
    }
        for(int i=0; i<10 ; i++){
        {
            if(card[i].suit=='h')
            {
                cout << "suit: Heart number: "<< card[i].value << endl;
            }

            else{
                continue;}
        }

    }

    return 0;
}
