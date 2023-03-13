#include<iostream>
using namespace std;
int main()
{
    int score;
    cout<<"Enter your score : ";
    cin>>score;
    
    cout<<"You got a grade : ";
    switch(score/10)
    {
        case 10  
:       cout<<'A';
break;
        case 9
:       cout<<'A';
break;
        case 8
:       cout<<'A';
break;
        case 7
:       cout<<'B';
break;
        case 6
:       cout<<'C';
break;
        case 5
:       cout<<'D';
break;
        default
:       cout<<'E';
break;
    }
    cout<<endl;

}
