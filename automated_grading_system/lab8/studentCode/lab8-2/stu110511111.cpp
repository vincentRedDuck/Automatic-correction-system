#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int findChar(string, char);

int main ()
{
    string str;
    cout << "Enter message: ";
    getline(cin, str);
    string end("Stop");
    while (strcmp(str.c_str(), end.c_str())!=0)
    {
        for (int i=0; i<52; i++)
        {
            if(i<26)
            {
                char a = char(i+65);
                int ans = findChar(str,a);
                if (ans!=0)
                {
                    cout << char(i+65) << ": " << ans << '\n';
                }
            }
            else
            {
                char a = char(i+71);
                int ans = findChar(str,a);
                if (ans!=0)
                {
                    cout << char(i+71) << ": " << ans << '\n';
                }
            }
        }
        
        cout << "Enter message: ";
        getline(cin, str);
    }
    return 0;
}

int findChar(string s, char c)
{
    int len = s.length();
    int num = 0;
    for (int i=0; i<len; i++)
    {
        if (s[i]==c)
        {
            num++;
        }
    }
    

    return num;
}
