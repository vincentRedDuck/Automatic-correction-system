#include <iostream>
using namespace std;
int main()
{
int grade = 0;

cout << "Enter your score : ";
cin >> grade;

switch(grade){
    case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: case 100:
        cout << "You got a grade : A" << endl;
        break;
    case 85: case 86: case 87: case 88: case 89:
        cout << "You got a grade : A" << endl;
        break; 
    case 80: case 81: case 82: case 83: case 84:
         cout << "You got a grade : A" << endl;
        break; 
    case 77: case 78: case 79:
         cout << "You got a grade : B" << endl;
        break;
    case 73: case 74: case 75: case 76:
         cout << "You got a grade : B" << endl;
        break;
    case 70: case 71: case 72:
         cout << "You got a grade : B" << endl;
        break;
    case 67: case 68: case 69:
         cout << "You got a grade : C" << endl;
        break;
    case 63: case 64: case 65: case 66:
         cout << "You got a grade : C" << endl;
        break;
    case 60: case 61: case 62:
         cout << "You got a grade : C" << endl;
        break;
    case 50: case 51: case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 59: 
         cout << "You got a grade : D" << endl;
        break;
    default:
         cout << "You got a grade : E" << endl;
         break;
}
     return 0;
}
