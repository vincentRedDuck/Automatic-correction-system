#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

struct student
{
	string ID;
	string name;
	int *score;
	int num_score;
	double average;
};


int main (int argc, char **argv)
{
	ifstream fin(argv[1]);
	string line;
	int e=0;
	while (getline(fin,line))
		e++;
	fin.close();
	fin.open(argv[1]);
	const int a = e;
	student stu[a];
	int j=0;
	double sum1=0;
	while (getline(fin,line))
	{
		stringstream ss;
		ss << line;
		ss >> stu[j].ID >> stu[j].name >> stu[j].num_score;

		stu[j].score = new int [stu[j].num_score];
		cout << stu[j].ID << " " << stu[j].name << " ";
		for (int i=0; i<stu[j].num_score; i++)
		{
			ss >> (stu[j].score)[i];
			cout << (stu[j].score)[i] << " ";
		}

		for (int i=1; i<stu[j].num_score; i++)
		{
			int key = (stu[j].score)[i];
			int f = i-1;
			while (key < (stu[j].score)[f] && f>=0)
			{
				(stu[j].score)[f+1] = (stu[j].score)[f];
				f--;
			}
			(stu[j].score)[f+1] = key;
		}

		int sum =0;
		if (stu[j].num_score >=10)
		{
			for(int k=0; k<10; k++)
				sum += (stu[j].score)[stu[j].num_score-k-1];
			stu[j].average = double(sum)/10;
		}
		else 
		{
			for (int k=0; k<stu[j].num_score; k++)
				sum += (stu[j].score)[k];
			stu[j].average = double(sum)/stu[j].num_score;
		}
		cout << stu[j].average << endl;
		sum1 += stu[j].average;
		j++;	

	}
	double average = sum1 / a;
	double temp=0;
	for (int i=0; i<a; i++)
	{
		temp += pow(stu[i].average - average, 2);
	}
	cout << sqrt(temp / a) << endl;
		


	return 0;
}
