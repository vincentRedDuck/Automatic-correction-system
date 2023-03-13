#include<iostream>
using namespace std;

char out(int score){
    switch(score){
        case 80 ... 100:
            return 'A';
            break;
        case 70 ... 79:
            return 'B';
            break;
        case 60 ... 69:
            return 'C';
            break;
        case 50 ... 59:
            return 'D';
            break;
        case 1 ... 49:
            return 'E';
        default:
            cerr<<"error";
    }
}
        
int main(){
    cout<<"Enter your score : ";
    int score;
    cin>>score;
    cout<<"You got a grade : "<<out(score)<<endl;
    return 0;
}
