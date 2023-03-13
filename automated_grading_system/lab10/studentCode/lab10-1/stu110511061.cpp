#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main (int argc, char **argv)
{
	string str, A[10],URL, B,C;
	char ch, ch2;
	int i=0;

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	while(getline(fin,URL))
	{
		istringstream iss(URL);
		iss.ignore(8,'/');
		iss.ignore(8,'/');
		getline(iss, str, '/');
		fout << "=====" << endl;
		fout << "Domain name: " << str << endl;
		str.clear();
	
		while(getline(iss, A[i], '/'))
		{
			i++;
		}
	
		istringstream iss2(A[i-1]);
		getline(iss2,str,'?');
		fout << "Method: " << str << endl;
		str.clear();

		while(getline(iss2,B,'='))
		{
			getline(iss2,C,'&');
			if (C.compare("") != 0 ) 
			{
				fout << B << ": " << C << endl;
			
			}
			C.clear();
		}

	}

	fout << "=====" << endl;

	return 0;
}

