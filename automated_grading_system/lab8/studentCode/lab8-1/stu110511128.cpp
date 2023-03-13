#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;
int main(){int a,b,c,d;
	   char x1,x2;
	while(1){
	cout << "Enter first point:";
	cin >> x1 >> a >> x1 >> b >> x1;
	cout << "Enter second point:";
	cin >> x2 >> c >> x2 >> d >> x2;
	if(a==0&&b==0&&c==0&&d==0){
		break;}
	cout << "Distance: "<< sqrt((a-c)*(a-c)+(b-d)*(b-d))<< endl;
	}

		return 0;
}
