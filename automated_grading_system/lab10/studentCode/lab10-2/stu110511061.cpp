#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;
struct mons
{
	int num;
	string jaN;
	string enN;
	string chN;
	bool myMons;
};

int main (int argc, char ** argv) 
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	mons A[500];
	string B, err;
	int i=0;
	stringstream ss;

	for(int j=0; j<493; j++)
	{
		A[j].myMons = false;
		getline(fin, B);
		ss.str(B);
		ss >> A[j].num >> A[j].jaN >> A[j].enN;
		ss >> err ;
		if(isalpha(err[0]))
		{
			A[j].enN = A[j].enN + " " + err;
			ss >> A[j].chN;
		}
		else
			A[j].chN = err;
		fout << setfill('0') << setw(3) << A[j].num << " " <<  A[j].enN << " " << A[j].chN << endl;
		ss.clear();
		ss.str("");
	}
	fin.close();
	fout.close();

	ifstream fin2(argv[3]);
	ofstream fout2(argv[4]);

	string monster;
	string myMonsEn;
	string debug1, debug2;
	int myMonsNum;
	bool test = false;
	
	while(fin2 >> monster)
	{
		ss << monster;
		if (isalpha(ss.peek()))
		{
			ss >> myMonsEn;
			for(int i=0; i<493; i++)
			{
				if (myMonsEn == A[i].enN)
				{
					A[i].myMons = true;
					test = true;
				}
				else
				{
					debug1 = myMonsEn;
				}
			}
		}
		else if (isdigit(ss.peek()))
		{
			ss >> myMonsNum;
			for(int i=0; i<493; i++)
			{
				if (myMonsNum == A[i].num)
				{
					A[i].myMons = true;
				}
			}
		
		}
		if (test =false)
		{
			debug2 = debug2 + " " + debug1;
			for(int i=0; i<493; i++)
			{
				if (debug2 == A[i].enN)
				{
					A[i].myMons = true;
					debug2.clear();
				}
			}
		}
		test = false;
		myMonsEn.clear();
		ss.str("");
		ss.clear();
		
	}

	for (int i=0; i<493; i++)
	{
		if (A[i].myMons == true)
			fout2 << A[i].num << " " << A[i].enN << endl;
	}


	return 0;
}
