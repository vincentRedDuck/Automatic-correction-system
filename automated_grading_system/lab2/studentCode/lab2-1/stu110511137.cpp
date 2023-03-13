//Exercise 2-1
#include<iostream>
using namespace std;
int main(){
	int score;
	cout << "Enter your score : ";
	cin >> score;
	score = score/10;
	char grade;
	switch(score){
		case 10:
	       	case 9:
	       	case 8:
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
		default:
			grade = 'E';
	}
	cout << "You got a grade : " << grade <<endl;
	return 0;
}
