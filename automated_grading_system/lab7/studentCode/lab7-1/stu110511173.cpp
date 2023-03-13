#include <iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
};



int main()
{
    CARD card[10];
    int sprade[10];
    int heart[10];
    
    for(int i=1 ; i<=10 ; i++)
    {
        cout << "#" << i << " card suit: ";
        cin >> card[i-1].suit ;
        cout << "#" << i << " card number: ";
        cin >> card[i-1].value ;
    }

    cout << endl << "after sort" << endl;
    
    int a = 0;
    int b = 0;
    
    for(int i = 0; i<10 ; i++)
    {
        if(card[i].suit == 's')
        {
            sprade[a] = card[i].value;
            a++;
        }
        else if(card[i].suit == 'h')
        {
            heart[b] = card[i].value;
            b++;
        }
    }
//sprade    
    for(int jdx = 1; jdx<a ; jdx++)
    {
        int key = sprade[jdx];
        int idx = jdx - 1;
        while(idx >= 0 && sprade[idx] > key)
        {
            sprade[idx+1] = sprade[idx];
            --idx;
        }
        sprade[idx+1] = key;
    }
    for(int i = 0; i<a ; i++)
    {
        cout <<"suit: Spades number: " <<sprade[i] << endl;
    }
//heart    
    for(int jdx = 1; jdx<b ; jdx++)
    {
        int key = heart[jdx];
        int idx = jdx - 1;
        while(idx >= 0 && heart[idx] > key)
        {
            heart[idx+1] = heart[idx];
            --idx;
        }
        heart[idx+1] = key;
    }
    for(int i = 0; i<b ; i++)
    {
        cout <<"suit: Heart number: " <<heart[i] << endl;
    }    
    
    return 0;
}
