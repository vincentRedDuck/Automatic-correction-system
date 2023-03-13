#include<iostream>
using namespace std;

int main()
{
int score ;
cout<<"Enter your score : ";
cin >> score;
switch(score)
{
    case 80 ... 100:
    cout <<"You got a grade : "<<'A'<<endl;
    break;
    case 70 ... 79:
    cout << "You got a grade : "<<'B'<<endl;
    break;
    case 60 ... 69:
    cout << "You got a grade : "<<'C'<<endl;
    break;
    case 50 ...59:
    cout<< "You got a grade : "<<'D'<<endl;
    break;
    case 1 ...49:
    cout << "You got a grade : "<<'E'<<endl;
    break;}
}
