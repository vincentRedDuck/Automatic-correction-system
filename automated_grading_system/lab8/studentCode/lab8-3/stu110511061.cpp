#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main ()
{
	cout << "Enter the sentence: ";
	string str;
	string task;
	string temp;
	getline (cin, str);
	int a=0, b=0;
	bool flag = false;

	while (strcmp(str.c_str(),"Stop the program"))
	{
		for(int i=0; i<strlen(str.c_str()); i++)
		{
			b = i;
			while (b < strlen(str.c_str()) && isalpha(str[b]))
			{	
				a += 1;	
				flag = true;	
				b++;
			}
			if(flag)
			{
				task = str.substr(i,a);
				i += (a-1);
				temp = task + " " + temp;
				task.clear();
				flag = false;
				a = 0;
			}
		}

		cout << temp << endl;
		temp.clear();
		cout << "Enter the sentence: ";
		getline (cin, str);
	}



	return 0;
}
