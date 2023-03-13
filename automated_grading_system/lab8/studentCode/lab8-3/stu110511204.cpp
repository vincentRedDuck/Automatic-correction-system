#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void reverseWord(string &str)
{
    for (int i = 0; i < strlen(str.c_str()) / 2; i++)
    {
        auto temp = str[i];
        str[i] = str[strlen(str.c_str()) - i - 1];
        str[strlen(str.c_str()) - i - 1] = temp;
    }
}

void reverseWord(string &str, const int &start, const int &end)
{
    for (int i = 0; i < (end - start + 1) / 2; i++)
    {
        char temp = str[start + i];
        str[start + i] = str[end - i];
        str[end - i] = temp;
    }
}

void reverseSentence(string &str)
{
    reverseWord(str);
    int start = 0;
    int end = -2;
    for (int i = 0; i < strlen(str.c_str()); i++)
    {
        if (str[i] == ' ')
        {
            start = end + 2;
            end = i - 1;
            reverseWord(str, start, end);
        }
        if (i == (strlen(str.c_str()) - 1))
        {
            start = end + 2;
            end = strlen(str.c_str()) - 1;
            reverseWord(str, start, end);
        }
    }
}

int main()
{
    string str;
    while (!cin.eof())
    {
        cout << "Enter the sentence: ";
        getline(cin, str);
        if (str == "Stop the program")
            break;
        reverseSentence(str);
        for (int i = 0; i < strlen(str.c_str()); i++)
            cout << str[i];
        cout << endl;
    }
    return 0;
}
