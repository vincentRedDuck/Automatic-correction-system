#include <iostream>

using namespace std;

int main(void){
	int score = 0;
	int deciscore = 0;
	char grade = ' ';
	
	cout << "Enter your score : ";
	cin >> score;
	deciscore = score / 10;

	switch(deciscore){
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
			break;	
	
	}

	cout << "You got a grade : " << grade <<endl;

	return 0;
}
