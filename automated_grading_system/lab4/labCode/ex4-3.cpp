#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool IsLeapYear(int x)
{
    return ((x % 4 == 0) && (x % 100 != 0) || (x % 400) == 0);
}

int FirstDay(int x)
{
    return ((x + (x - 1) / 4 - (x - 1) / 100 + (x - 1) / 400)) % 7;
}

void PrintCalendar(int year)
{
    int idx = 0;
    int space = FirstDay(year);
    for (int i = 1; i <= 12; i++)
    {
        cout << "============= " << i << " ============" << endl;
        cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            while (idx < space)
            {
                cout << "    ";
                idx++;
            }
            for (int j = 0; j < 31; j++)
            {
                cout << setw(4) << right << j + 1;
                idx++;
                if (idx % 7 == 0)
                    cout << endl;
            }
            space = idx % 7;
            idx = 0;
            cout << endl;
        }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        {
            while (idx < space)
            {
                cout << "    ";
                idx++;
            }
            for (int j = 0; j < 30; j++)
            {
                cout << setw(4) << right << j + 1;
                idx++;
                if (idx % 7 == 0)
                    cout << endl;
            }
            space = idx % 7;
            idx = 0;
            cout << endl;
        }
        break;
        case 2:
        {
            if (IsLeapYear(year))
            {
                while (idx < space)
                {
                    cout << "    ";
                    idx++;
                }
                for (int j = 0; j < 29; j++)
                {
                    cout << setw(4) << right << j + 1;
                    idx++;
                    if (idx % 7 == 0)
                        cout << endl;
                }
                space = idx % 7;
                idx = 0;
                cout << endl;
            }
            else
            {
                while (idx < space)
                {
                    cout << "    ";
                    idx++;
                }
                for (int j = 0; j < 28; j++)
                {
                    cout << setw(4) << right << j + 1;
                    idx++;
                    if (idx % 7 == 0)
                        cout << endl;
                }
                space = idx % 7;
                idx = 0;
                cout << endl;
            }
        }
        break;
        }
    }
}

int main()
{
    int year;
    while (1)
    {
        cout << "Enter the year:";
        cin >> year;
        cout << endl;
        if (year <= 0)
        {
            cout << "Stop!!" << endl;
            break;
        }
        else PrintCalendar(year);
    }

    return 0;
}