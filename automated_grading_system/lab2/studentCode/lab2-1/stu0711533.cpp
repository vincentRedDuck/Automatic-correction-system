//Program: ex2-1.cpp
#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "Enter your score : ";
    cin >> score;
    char grade;
    grade = (score >= 80) ? 'A' : ((score >= 70) ? 'B' : ((score >= 60) ? 'C' : ((score >= 50) ? 'D' : 'E')));
    switch (grade) {
        case 'A':
            cout << "You got a grade : A" << endl;
            break;
        case 'B':
            cout << "You got a grade : B" << endl;
            break;
        case 'C':
            cout << "You got a grade : C" << endl;
            break;
        case 'D':
            cout << "You got a grade : D" << endl;
            break;
        case 'E':
            cout << "You got a grade : E" << endl;
            break;
    }
    return 0;
}
