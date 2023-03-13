#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1, str[100];
    int length;
    char ch;
    bool end = 0;
    while(1)
    {
        for(int i = 0; i < 100; i++)
        {
            str[i] = "\0";
        }
        length = 0;
        end = 0;
        cout << "Enter the sentence: ";
        getline(cin, str1);
        if(str1 == "Stop the program")
        {
            break;
        }
        for(int i = 0; !end;)
        {
            for(int j = 0; 1; j++)
            {
                ch = str1[j];
                if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                {
                    str[i] += ch;
                }
                else if(ch == '\0')
                {
                    end = 1;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        for(int i = 99; i >= 0; i--)
        {
            if(str[i] != "\0")
            {
                cout << str[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
