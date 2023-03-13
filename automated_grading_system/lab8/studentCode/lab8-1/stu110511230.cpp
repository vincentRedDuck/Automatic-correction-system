#include <iostream>
#include <cmath>
using namespace std;

struct point {
	char z;
	int a;
	char y;
	int b;
	char x;
};

double dis;

int main (){
	point pa;
	point pb;
	cout << "Enter first point:";
	cin >> pa.z >> pa.a >> pa.y >> pa.b >> pa.x;
	cout << "Enter second point:";
	cin >> pb.z >> pb.a >> pb.y >> pb.b >> pb.x;
	while(((pa.a != 0) || (pa.b != 0)) ||  ((pb.a !=0) || (pb.b !=0))){
		dis = sqrt((abs(pa.a-pb.a)*abs(pa.a-pb.a)+abs(pa.b-pb.b)*abs(pa.b-pb.b)));
		cout << "Distance: " << dis << endl;
                cout << "Enter first point:";
        	cin >> pa.z >> pa.a >> pa.y >> pa.b >> pa.x;
        	cout << "Enter second point:";
        	cin >> pb.z >> pb.a >> pb.y >> pb.b >> pb.x;
	}
	return 0;
}
