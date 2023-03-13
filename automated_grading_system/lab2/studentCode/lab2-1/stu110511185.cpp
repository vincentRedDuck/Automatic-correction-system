#include<iostream>
using namespace std;
int main(){
int score;
cout<<"Enter your score : ";
cin>>score;
switch(score/10){
case 8: case 9: case 10:
    cout<<"You got a grade : A";
    break;
case 7:
    cout<<"You got a grade : B";
    break;
case 6:
    cout<<"You got a grade : C";
    break;
case 5:
    cout<<"You got a grade : D";
    break;
case 4: case 3: case 2: case 1: case 0:
    cout<<"You got a grade : E";
    break;
    }
cout<<endl;
}
