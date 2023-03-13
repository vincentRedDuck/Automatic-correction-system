#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	cout << "Enter first point:";
	string pt1; getline(cin, pt1);
	cout << "Enter second point:";
	string pt2; getline(cin, pt2);

	int pt1Len = pt1.length();
	int a1, a2, a3;
	for(int i=0; i<pt1Len; i++) {
		if(pt1[i]=='(')
			a1 = i;
		else if(pt1[i]==',')
			a2 = i;
		else if(pt1[i]==')')
			a3 = i;
	}
    

	int pt2Len = pt2.length();
	int b1, b2, b3;
	for(int i=0; i<pt2Len; i++) {
		if(pt2[i]=='(')
			b1 = i;
		else if(pt2[i]==',')
			b2 = i;
		else if(pt2[i]==')')
			b3 = i;
	}
    

	string sx1, sx2, sy1, sy2;
	for(int i=a1+1; i<a2; i++) {
		sx1 += pt1[i];
	}
	for(int i=a2+1; i<a3; i++) {
		sy1 += pt1[i];
	}
	for(int i=b1+1; i<b2; i++) {
		sx2 += pt2[i];
	}
	for(int i=b2+1; i<b3; i++) {
		sy2 += pt2[i];
	}
	int x1 = atoi(sx1.c_str());
	int x2 = atoi(sx2.c_str());
	int y1 = atoi(sy1.c_str());
	int y2 = atoi(sy2.c_str());
	while(!(x1==0 && x2==0 && y1==0 && y2==0)) {

		double dis = sqrt(pow((x1-x2), 2)+pow((y1-y2), 2));
		cout << "Distance: " << dis << endl;

		cout << "Enter first point:";
		string pt1; getline(cin, pt1);
		cout << "Enter second point:";
		string pt2; getline(cin, pt2);

		pt1Len = pt1.length();
		for(int i=0; i<pt1Len; i++) {
			if(pt1[i]=='(')
				a1 = i;
			else if(pt1[i]==',')
				a2 = i;
			else if(pt1[i]==')')
				a3 = i;
		}

		pt2Len = pt2.length();
		for(int i=0; i<pt2Len; i++) {
			if(pt2[i]=='(')
				b1 = i;
			else if(pt2[i]==',')
				b2 = i;
			else if(pt2[i]==')')
				b3 = i;
		}
        
        sx1 = "";
		sx2 = "";
		sy1 = "";
		sy2 = "";
		for(int i=a1+1; i<a2; i++) {
			sx1 += pt1[i];
		}
		for(int i=a2+1; i<a3; i++) {
			sy1 += pt1[i];
		}
		for(int i=b1+1; i<b2; i++) {
			sx2 += pt2[i];
		}
		for(int i=b2+1; i<b3; i++) {
			sy2 += pt2[i];
		}
		x1 = atoi(sx1.c_str());
		x2 = atoi(sx2.c_str());
		y1 = atoi(sy1.c_str());
		y2 = atoi(sy2.c_str());
	}
	return 0;
}
