//File:ex2-1.cpp
#include <iostream>
using namespace std;

int main()
{
    int sc;
    cout << "Enter your score : " ;
    cin >> sc;
    switch (sc/10)
    {
        case 10:
        case 9:
        case 8:
            cout << "You got a grade : A" <<endl;
            break; 
        case 7:
            cout << "You got a grade : B" <<endl;
            break;
        case 6:
            cout << "You got a grade : C" <<endl;
            break;
        case 5:
            cout << "You got a grade : D" <<endl;
            break;
        default:
            cout << "You got a grade : E" <<endl;
            break;
    }       
    return 0;
}
