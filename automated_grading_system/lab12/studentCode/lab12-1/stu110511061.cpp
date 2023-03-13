#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	int num ;
	cin >> num;
	
	while (num != -1)
	{
		int **vec = new int *[num];
		for (int i=0; i<num; i++)
		{
			vec[i] = new int [num];
		}	
		
		vec[0][0] = 1;

		for (int i=1; i<num; i++)
		{
				vec[0][i] = vec[0][i-1] + 2;
		}
		
		int k = num-1;
		int line=0, column=num-1;

		while (k >= 1)
		{
			for (int i=1; i<=k; i++)
			{
				if (vec[line][column]+2 <= num*num)
					vec[++line][column] = vec[line][column] + 2;
				else 
				{
					vec[++line][column] = 2;
				}
			}

			for (int i=1; i<=k; i++)
			{
				if (vec[line][column]+2 <= num*num)
					vec[line][--column] = vec[line][column] + 2;
				else 
				{
					vec[line][--column] = 2;
				}
			}
			k--;
			for (int i=1; i<=k; i++)
			{
				if (vec[line][column]+2 <= num*num)
					vec[--line][column] = vec[line][column] + 2;
				else 
				{
					vec[--line][column] = 2;
				}
			}
		
			for (int i=1; i<=k; i++)
			{
				if (vec[line][column]+2 <= num*num)
					vec[line][++column] = vec[line][column] + 2;
				else 
				{
					vec[line][++column] = 2;
				}
			}
			k--;
		}

		for (int i=0; i<num; i++)
		{
			for (int j=0; j<num; j++)
			{
				cout << setw(5) << right << vec[i][j];
		
			}
			cout << endl;
	
		}
		cin >> num;
	}
	
	return 0;
}
