#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string str;
    char _char;
    int count = 0;
    while (1)
    {
        cout << "Enter message: ";
        getline(cin, str);
        if (str == "Stop")
            break;
        for (int i = 65; i < 123; i++)
        {
            _char = i;
            if (i == 91 || i == 92 || i == 93 || i == 94 || i == 95 || i == 96)
                continue;
            else
            {
                for (int j = 0; j < strlen(str.c_str()); j++)
                {
                    if (str[j] == _char)
                        count++;
                }
                if (count != 0)
                {
                    cout << _char << ": " << count << endl;
                    count = 0;
                }
            }
        }
    }
    return 0;
}