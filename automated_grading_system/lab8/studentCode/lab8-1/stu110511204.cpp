#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    bool flag1 = false, flag2 = false;
    while (1)
    {
        cout << "Enter first point:";
        cin >> str1;
        cout << "Enter second point:";
        cin >> str2;
        int x, y;
        x = str1.find("(");
        y = str1.find(",");
        double x1 = stod(str1.substr(x + 1, y - x + 1));
        x = str1.find(",");
        y = str1.find(")");
        double y1 = stod(str1.substr(x + 1, y - x + 1));
        x = str2.find("(");
        y = str2.find(",");
        double x2 = stod(str2.substr(x + 1, y - x + 1));
        x = str2.find(",");
        y = str2.find(")");
        double y2 = stod(str2.substr(x + 1, y - x + 1));
        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            break;
        double r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        cout << "Distance: " << r << endl;
    }
    return 0;
}
