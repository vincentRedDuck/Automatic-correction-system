#include <iostream>

void encoder(int);
void decoder(int);

int main ()
{
    std::cout << "1: encoder 2: decoder 3: quit: ";
    int mode{0};
    std::cin >> mode;
    while (mode!=3)
    {
        if (mode==1 || mode==2)
        {
            std::cout << "Please enter sentences length: ";
            int length{0};
            std::cin >> length;
            if (mode==1)
            {
                encoder (length);
            }
            else if(mode==2)
            {
                decoder (length);
            }
        }
        else 
        {
            std::cout << "invalid input";
        }
        std::cout << "1: encoder 2: decoder 3: quit: ";
        std::cin >> mode;
    }
    return 0;
}

void encoder(int x)
{
    char lineOne[50] = {0};
    char lineTwo[50] = {0};
    for (int i=0; i<x; i++)
    {
        if (i%2==0)
        {
            std::cin >> lineOne[i/2];
        }
        else 
        {
            std::cin >> lineTwo[i/2];
        }
    }
    for (int i=0; i<x/2+x%2; i++)
    {
        std::cout << lineOne[i];
    }
    for (int i=0; i<x/2; i++)
    {
        std::cout << lineTwo[i];
    }
    std::cout << "\n\n";
}

void decoder(int x)
{ 
    char lineOne[50] = {0};
    char lineTwo[50] = {0};
    for (int i=0; i<x/2+x%2; i++)
    {
        std::cin >> lineOne[i];
    }
    for (int i=0; i<x/2; i++)
    {
        std::cin >> lineTwo[i];
    }
    for(int i=0; i<x; i++)
    {
        if((i%2)==0)
        {
            std::cout << lineOne[i/2];
        }
        else
        { 
            std::cout << lineTwo[i/2];
        }
    }
    std::cout << "\n\n";
}
