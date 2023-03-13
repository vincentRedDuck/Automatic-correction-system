#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	/*char in;
	cout<<"Choose a game to play : "
	cin>>in;
	if(in == 'A'){
		char p1,p2;
		cout<<"Enter s, r, p for player 1 : ";
		cin>>p1;
		cout<<"Enter s, r, p for player 2 : ";
		cin>>p2;

		if(p1 == p2)
			cout<<"Two players tie"<<endl;
		else if((p1 == 's'&& p2 == 'p')||(p1 == 'p' && p2 == 'r')||(p1 == 'r' && p2 == 's'))
			cout<<"Player 1 win";
		else
			cout<<"Player 2 win";
	}
	else if(in == 'B'){*/
		int x;
		cout<<"Enter your score : ";
		cin>>x;
		cout<<"You got a grade : ";
		switch(x/10){
			case 10:
			case 9:
			case 8:
				cout<<"A";
				break;
			case 7:
				cout<<"B";
				break;
			case 6:
				cout<<"C";
				break;
			case 5:
				cout<<"D";
				break;
			default:
				cout<<((x>0)?"E":"X");
				break;
	}
	cout<<endl;
	/*else{

	}*/



}
