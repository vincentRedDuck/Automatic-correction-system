#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>

using namespace std;

string decoder(string);
string encoder(string);

struct morse
{
	char eng;
	string code;
};
morse A[36];


int main (int argc, char **argv)
{
	ifstream fin1 (argv[1]);
	ifstream fin2 ("code.txt");	
	ofstream fout (argv[2]);

	stringstream ss1;
	ss1 << argv[3];

	char a;
	ss1 >> a;
	string line;

	for (int i=0; i<36; i++)
	{
		fin2 >> A[i].eng >> A[i].code;
	}
	if  (a == 'e')
	{
		while (getline(fin1, line))
		{
			fout << encoder(line);
		}
	}
	else if (a == 'd')
	{
		while (getline(fin1, line))
		{
			fout << decoder(line);
		}
	
	}

	fin1.close();
	fin2.close();
	fout.close();

	return 0;
}

string encoder(string a)
{
	stringstream ss2;
	ss2 << a;
	string encode;

	char ch;
	while(ss2.get(ch))
	{
		for(int i=0; i<36; i++)
		{
			if (ch == A[i].eng)
				encode += A[i].code +  (ss2.peek() == ' ' ? "       " : "   ");
		}
	}
	encode += "\n";

	return encode;
}

string decoder (string a)
{
	stringstream ss3;
	ss3 << a;
	
	int count=0;
	string str;
	string decode;
	char ch;

	while(ss3.get(ch))
	{
		if (ch != ' ')
		{
			str += ch;
			count = 0;
			if (ss3.peek() != EOF)
				continue;
		}
		else
		{
			count++;
		}
		for (int i=0; i<36; i++)
		{
			if (str == A[i].code)
			{
				decode += A[i].eng;
				str.clear();
			}
			else 
			{
				if (count == 7)
				{
					decode += " ";
					count = 0;
					str.clear();
				}
			}
		
		}
	}
	decode += "\n";

	return decode;
}
