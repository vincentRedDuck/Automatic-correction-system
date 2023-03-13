#include <iostream>
using namespace std;

struct CARD 
{
	char suit;
	int value;
};

void sort(CARD []);


int main ()
{
	CARD card[10];
	
	for (int i=0; i<10; i++)
	{
		cout << "#" << i+1 << " card suit: ";
		cin >> card[i].suit;
		cout << "#" << i+1 << " card number: ";
		cin >> card[i].value;
	}
	
	sort (card);



	return 0;
}



void sort (CARD card[] )
{
	int spades[10];
	int heart[10];
	int j=0;
	int k=0;

	for (int i=0; i<10; i++)
	{
		if (card[i].suit == 's')
			spades[j++] = card[i].value;		
		else 
			heart[k++] = card[i].value;
	}
	
	for (int i=1; i<j; i++)
	{
		int key;
		while (spades[i] < spades[i-1])
		{
			key = spades[i];
			spades[i] = spades[i-1];
			spades[i-1] = key;
			i--;
		}
	}
	
	cout << endl << "after sort" << endl;

	for (int i=0; i<j; i++)
		cout << "suit: Spades number: " << spades[i] << endl;

	for (int i=1; i<k; i++)
	{
		while (heart[i] < heart[i-1])
		{
			swap (heart[i], heart[i-1]);
			i--;
		}
	}

	for (int i=0; i<k; i++)
		cout << "suit: Heart number: " << heart[i] << endl;
}

