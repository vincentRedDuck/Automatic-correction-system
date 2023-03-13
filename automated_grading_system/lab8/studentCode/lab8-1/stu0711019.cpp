#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void Dis(int,int,int,int);
int main(){


	string str1, str2;
	int x1,y1,x2,y2;
	cout << "Enter first point:";
	cin >> str1;
	cout << "Enter second point:";
	cin >> str2;
	int c1 = str1.find(",",0);
	int c2 = str1.find(")",0);
	int c3 = str2.find(",",0);
	int c4 = str2.find(")",0);

	x1 = stoi(str1.substr(1,c1-1));
	y1 = stoi(str1.substr(c1+1,c2-c1));
	x2 = stoi(str2.substr(1,c3-1));
	y2 = stoi(str2.substr(c3+1,c4-c3));
	
	while(x1!=0 || x2!=0 || y1!=0 || y2!=0){
		cout << "Distance: ";
		Dis(x1,y1,x2,y2);

		cout << "Enter first point:";
		cin >> str1;
		cout << "Enter second point:";
		cin >> str2;

		int c1 = str1.find(",",0);
		int c2 = str1.find(")",0);
		int c3 = str2.find(",",0);
		int c4 = str2.find(")",0);
	
		x1 = stoi(str1.substr(1,c1-1));
		y1 = stoi(str1.substr(c1+1,c2-c1));
		x2 = stoi(str2.substr(1,c3-1));
		y2 = stoi(str2.substr(c3+1,c4-c3));
	
	}
	return 0;
}

void Dis(int x1, int y1, int x2, int y2){
	
	float distance=0;
	distance = sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
	cout << distance << endl;
}

