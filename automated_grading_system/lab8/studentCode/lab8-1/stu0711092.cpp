#include<iostream>
#include<string>
#include<math.h>
#include<cstdlib>
using namespace std;

double distance(int,int,int,int);

int main(){

	string point1;
	string point2;
	cout << "Enter first point:";
	cin >> point1;
	cout << "Enter second point:";
	cin >> point2;
	int period1 = point1.find(",",0);
	int co1 = point1.find(")",0);
        int period2 = point2.find(",",0);
	int co2 = point2.find(")",0);

	int x1 = stoi(point1.substr(1,period1-1));
	int y1 = stoi(point1.substr(period1+1,co1-1));
	int x2 = stoi(point2.substr(1,period1-1));
	int y2 = stoi(point2.substr(period2+1,co2-1));

	while( x1 != 0 || y1 != 0 || x2 != 0 || y2 !=0){
	cout << "Distance: "<< distance(x1,y1,x2,y2)<<endl;

	cout << "Enter first point:";
	cin >> point1;
	cout << "Enter second point:";
	cin >> point2;

	int period1 = point1.find(",",0);
	int co1 = point1.find(")",0);
        int period2 = point2.find(",",0);
	int co2 = point2.find(")",0);

	x1 = stoi(point1.substr(1,period1-1));
	y1 = stoi(point1.substr(period1+1,co1-1));
	x2 = stoi(point2.substr(1,period2-1));
	y2 = stoi(point2.substr(period2+1,co2-1));


	}
}

double distance(int x1,int y1,int x2,int y2){
	int X = 0;
	int Y = 0;
	double rs;
	X = abs(x1-x2);
	Y = abs(y1-y2);
	rs = sqrt(pow(X,2)+pow(Y,2));
	return rs;


}
