#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	cout << "Enter message: ";
	char str[80];
	char alpha[53];
	cin.getline(str, 80);
	int A1[53]={0};

	while(strcmp(str,"Stop"))
	{
		for (int i=0; i < strlen(str); i++ )
		{
			for(int j=0; j<52; j++)
			{
				if (j<26)
					alpha[j] = char('A'+j);
				else
					alpha[j] = char('a'+j-26);

				if(str[i] == alpha[j])
				{
					A1[j]++;
				}
			}
		}
	
		for(int i=0; i<52; i++)
		{
			if(A1[i] > 0)
				cout << alpha[i] << ": " << A1[i] << endl;
		}
		cout << "Enter message: ";
		cin.getline(str,80);
		for (int i=0; i<53; i++)
		{
			A1[i] = {0};
		}
	}


	return 0;
}
