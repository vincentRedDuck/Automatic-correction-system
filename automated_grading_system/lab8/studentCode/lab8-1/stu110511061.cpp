#include <iostream>
#include <cmath>

using namespace std;


int main ()
{
	int A[4];
	char B[6];	
	cout << "Enter first point:";
	cin >> B[0] >> A[0] >> B[1] >> A[1] >> B[2];
	cout << "Enter second point:";
	cin >> B[3] >> A[2] >> B[4] >> A[3] >> B[5];

	while(A[0]!=0 || A[1]!=0 || A[2]!=0 || A[3]!=0)
	{
		cout << "Distance: " << sqrt( pow(A[0]-A[2], 2) + pow(A[1]-A[3], 2)) << endl;
		cout << "Enter first point:";
		cin >> B[0] >> A[0] >> B[1] >> A[1] >> B[2];
		cout << "Enter second point:";
		cin >> B[3] >> A[2] >> B[4] >> A[3] >> B[5];
	}
	

	return 0;
}
