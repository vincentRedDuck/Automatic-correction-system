#include <iostream>

struct CARD
{
    char suit;
    int value;
};

void SortCard(CARD[10]);

int main ()
{
    CARD poker[10];
    for (int i=0; i<10;i++)
    {
        std::cout << "#" << i+1 << " card suit: ";
        std::cin >> poker[i].suit;
        std::cout << "#" << i+1 << " card number: ";
        std::cin >> poker[i].value;
    }
    std::cout << '\n';
    SortCard (poker);

    return 0;
}

void SortCard (CARD x[10])
{
    for (int i=1; i<10; i++)
    {
        char changeSuit{x[i].suit};
        int changeValue{x[i].value};
        int loc{i-1};
        while (loc>=0 && ((x[loc].suit=='h' && changeSuit=='s') || (x[loc].suit=='s' && changeSuit=='s' &&  x[loc].value>changeValue) || (x[loc].suit=='h' && changeSuit=='h'&& x[loc].value>changeValue)))
        {
            x[loc+1].suit = x[loc].suit;
            x[loc+1].value = x[loc].value;
            loc--;
        }
            x[loc+1].suit = changeSuit;
            x[loc+1].value = changeValue;
    }
    std::cout << "after sort\n";
    for (int i=0; i<10; i++)
    {
        std::cout << "suit: ";
        if (x[i].suit=='h')
        {
            std::cout << "Heart ";
        }
        else
        {
            std::cout << "Spades ";
        }
        std::cout << "number: " << x[i].value << '\n';
    }    
}
