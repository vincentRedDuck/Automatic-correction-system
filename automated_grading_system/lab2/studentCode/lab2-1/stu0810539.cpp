#include <iostream>
using namespace std;
int main ()
{
    int score=0;
    int grade;
    int level = 0;
    cout << "Enter your score :";
    cin >> score;
    level = score/10;
    switch (level){
        case 10:
        case 9:
        case 8:
            puts(" You got a grade : A");
            break;
        case 7:
            puts(" You got a grade : B");
            break;
        case 6:
            puts(" You got a grade : C");
            break;
        case 5:
            puts(" You got a grade : D");
            break;
        default:
            puts(" You got a grade : E");
            break; 
        }

    return 0;
}


    
