#include <iostream>
using namespace std;

int main()

{

    int score;
    char grade;
    cout << "Enter your score : " ;
    cin >> score;
    
    if (score >= 80)
        grade = 'a';
    else if (score >= 70 )
        grade = 'b';
    else if (score >= 60)
        grade = 'c';
    else if (score >= 50)
        grade = 'd';
    else
        grade = 'e';

    switch(grade)
    {
        case 'a':
            cout << "You got a grade : A" << endl;
            break;
        case 'b':
            cout << "You got a grade : B" << endl;
            break;
        case 'c':
            cout << "You got a grade : C" << endl;
            break;
        case 'd':
            cout << "You got a grade : D" << endl;
            break;
        default:
            cout << "You got a grade : E" << endl;
            break;
    }

    return 0;   
}
