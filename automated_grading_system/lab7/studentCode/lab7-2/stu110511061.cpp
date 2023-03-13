#include <iostream>
using namespace std;


void encoder(char [], int);
void decoder(char [], int);

int main ()
{
	int a=0, b;
	char A[100];

	
	while (a != 3 )
	{		
		cout << "1: encoder 2: decoder 3: quit: ";
		cin >> a;

		if (a>3 || a<1)
		{
			cout << "invalid input" << endl; 
			break;
		}
		else if (a == 3)
			break;
		else
		{
			cout << "Please enter sentences length: ";
			cin >> b;
		}

		for (int i=0; i<b; i++)
		{
			cin >> A[i];
		}
		
		if (a == 1)
			encoder(A,b);
		else
			decoder(A,b);
	
	}	
	return 0;
}




void encoder(char A[], int b)
{
	for (int i=0; i<b; i+=2)
	{
		cout << A[i];
	}
	
	for (int i=1; i<b; i+=2)
	{
		cout << A[i];
	}

	cout << endl << endl;

}


void decoder(char A[], int b)
{
	if (b % 2 == 0)
	{
		for (int i=0; i< b/2; i++)
		{
			cout << A[i] << A[b/2+i];
		}
	}
	else 
	{
		for (int i=0; i<b/2+1 ;i++)
		{
			cout << A[i];
			if(i != b/2)
				cout << A[b/2+1+i];
		}
	
	
	}
	cout << endl << endl;


}





