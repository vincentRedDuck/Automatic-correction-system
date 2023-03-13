#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

const int Max=10;

int main (int argc, char *argv[])
{
//	char *filename = argv[1];
	ifstream in_file(argv[1]);

	string A, num;
	int B=0, beg=0, end=0, sum=0, a=0;

	while(getline(in_file, A,'\n'))
	{
		for(int i=0; i<strlen(A.c_str()); i++ )
		{
			if (isdigit(A[i]))
			{
				num = num + A[i];			
			}
		}
		a++;
		sum += atoi(num.c_str());
		num.clear();
	}
	

	ofstream out_file(argv[2]);
	out_file << "The average is: " << fixed << setprecision(4) << double(sum) / a;

	in_file.close();
	out_file.close();

	return 0;
}
