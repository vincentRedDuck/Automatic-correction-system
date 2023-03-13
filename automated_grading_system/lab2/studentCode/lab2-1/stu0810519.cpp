#include <iostream>
using namespace std;

int main(){
	char grade;
	int score;

        cout << "Enter your score : ";
	cin >> score;
	switch(score/10){
		case 10:
			grade='A';
			break;
		case 9:
			grade='A';
                        break;
		case 8:
			grade='A';
                        break;
		case 7:
			grade='B';
                        break;
                case 6:
			grade='C';
                        break;
                case 5:
			grade='D';
                        break;
		default:
			grade='E';
	}
	cout << "You got a grade : " << grade << endl;
}
