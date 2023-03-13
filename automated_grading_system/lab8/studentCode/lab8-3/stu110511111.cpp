#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main ()
{
    cout << "Enter the sentence: ";
    string str;
    getline(cin, str);
    string end("Stop the program");
    string output[10];
    while (strcmp(str.c_str(),end.c_str())!=0)
    {
        int head = str.length()-1;
        int ending = str.length()-1;
        int count = 0;
        while (head>=0)
        {
            ending = head;
            while (!isalpha(str[ending]) && ending>=0)
            {
                head--;
                ending--;
            }
            while (isalpha(str[head]) && head>=0)
            {
                head--;
            }
            if (ending>=0)
            {
            output[count] = str.substr(head+1,ending-head);
            count++;
            }
        }
    for (int i=0; i<count; i++)
    {
        cout << output[i];
        if (i<count-1)
        {
            cout << ' ';
        }
    }
    cout << '\n';

    cout << "Enter the sentence: ";
    getline(cin, str);
    }
    

    return 0;
}
