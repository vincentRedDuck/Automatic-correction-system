#include <iostream>

using namespace std;

int main(){
    int score;
    char grade;

    cout << "Enter your score : ";
    cin >> score;
    cout << "You got a grade : ";

    switch (score/10)
    {
        case 8: case 9: case 10:
            grade = 'A';
            break;
        
        case 7:
            grade = 'B';
            break;
        
        case 6:
            grade = 'C';
            break;

        case 5:
            grade = 'D';
            break;

        case 1: case 2: case 3: case 4: case 0:
            grade = 'E';
            break;
        
        default:
            break;
    }

    cout << grade << endl;

    return 0;
}
