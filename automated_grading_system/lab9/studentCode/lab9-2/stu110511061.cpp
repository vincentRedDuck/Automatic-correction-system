#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct student 
{
	string name;
	int grade1;
	int grade2;
	int grade3;	
	double average;
};

int main (int argc, char **argv)
{
	ifstream in_file(argv[2]);
	
	int a;
	in_file >> a;

	string txt(argv[2]);

	student A[a];

	for (int i=0; i<a; i++)
	{
		in_file >> A[i].name >> A[i].grade1 >> A[i].grade2 >> A[i].grade3;
		A[i].average = (A[i].grade1 + A[i].grade2 + A[i].grade3)/3.0;
	}
	
	if(argc == 3)
		txt = txt + ".out";
	else
		txt = argv[3];

	if ( atoi(argv[1])==1)
	{
		student key;
		int j;
		for (int i=1; i<a; i++)
		{
			key = A[i];
			j = i-1;	
			while(key.average < A[j].average && j >= 0)
			{
				A[j+1] = A[j];
				j--;
			
			}
			A[j+1] = key;
		}

		ofstream out_file(txt);
		
		for (int i=0; i<a; i++)
		{
			out_file << A[i].name <<" "<< A[i].grade1 << " "<< A[i].grade2 <<" " << A[i].grade3 << " " << fixed << setprecision(4) << A[i].average << endl ;
		}
	}
	else
	{	
		student key1;
		int j;
		for (int i=1; i<a; i++)
		{
			key1 = A[i];
			j = i-1;
			while(strcmp(key1.name.c_str(), A[j].name.c_str()) < 0 && j >= 0)
			{
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = key1;
		}

		ofstream out_file(txt);
		
		for (int i=0; i<a; i++)
		{
			out_file << A[i].name << " " << A[i].grade1 << " " << A[i].grade2 << " " << A[i].grade3 << " " << fixed << setprecision(4) << A[i].average << endl ;
		}
	}

	return 0;
}
