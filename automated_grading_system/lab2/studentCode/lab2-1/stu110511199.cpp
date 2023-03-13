//File: ex2-1.cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter your score : ";
    cin >> score;
    switch (score/10) 
    {
        case 10:
            cout << "You got a grade : A" << endl;
            break;
        case 9:
            cout << "You got a grade : A" << endl;
            break;
        case 8:
            cout << "You got a grade : A" << endl;
            break;
        case 7:
            cout << "You got a grade : B" << endl;
            break;
        case 6:
            cout << "You got a grade : C" << endl;
            break;
        case 5:
            cout << "You got a grade : D" << endl;
            break;
        case 4:
            cout << "You got a grade : E" << endl;
            break;
        case 3:
            cout << "You got a grade : E" << endl;
            break;
        case 2:
            cout << "You got a grade : E" << endl;
            break;
        case 1:
            cout << "You got a grade : E" << endl;
            break;
        case 0:
            cout << "You got a grade : E" << endl;
            break;
        default: 
            break;
    }

    return 0;
}
