#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

void reversePrint(stringstream &ss)
{
    string tmp;
    if (ss.eof())
        return;
    ss >> tmp;
    reversePrint(ss);
    cout << tmp << " ";
}

int main()
{
    string str, ans;
    int _char;
    string tmp;
    while (1)
    {
        stringstream ss;
        cout << "Enter the sentence: ";
        getline(cin, str);
        if (str == "Stop the program")
            break;
        for (int i = 0; i < str.length(); i++)
        {
            _char = str[i];
            if (!(_char >= 65 && _char <= 90) && !(_char >= 97 && _char <= 122))
                str[i] = ' ';
        }
        ss << str;
        ans = "";
        while (ss >> tmp)
        {
            if (ans == "")
                ans += tmp;
            else
                ans = tmp + " " + ans;
        }
        cout << ans << endl;
        // ss << str;
        // reversePrint(ss);
        // cout << endl;
    }
    return 0;
}
