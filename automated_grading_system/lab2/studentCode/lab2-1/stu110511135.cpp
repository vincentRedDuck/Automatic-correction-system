#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "Enter your score : ";
    cin >> score;
    int score2 = score/10;
    switch (score2)
    {
        case 8:
        case 9:
        case 10:
            cout << "You got a grade : A"<< endl;
            break;
        case 7:
            cout << "You got a grade : B"<< endl;
            break;
        case 6:
            cout << "You got a grade : C"<< endl;
            break;
        case 5:
            cout << "You got a grade : D"<< endl;
            break;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            cout << "You got a grade : E"<< endl;
            break;

    }

return 0;
}
