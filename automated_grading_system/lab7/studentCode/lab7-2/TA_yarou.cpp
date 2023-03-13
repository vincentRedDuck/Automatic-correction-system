#include <iostream>

using namespace std;

void encoder()
{
    int len = 0;
    cout << " Please enter sentences length: ";
    cin >> len;
    if (len <= 0)
    {
        return;
    }
    char input[len];
    for (int i = 0; i < len; i++)
    {
        cin >> input[i];
        // cout << i << ":" << input[i] << endl;
    }
    int i = len;

    for (int k = 0; k < (i + 1) / 2; k++)
    {
        cout << input[k * 2];
    }
    for (int k = 0; k < i / 2; k++)
    {
        cout << input[k * 2 + 1];
    }
    cout << endl;
}
void decoder()
{
    int len;
    cout << " Please enter sentences length: ";
    cin >> len;
    if (len <= 0)
    {
        return;
    }
    char input[len];
    for (int i = 0; i < len; i++)
    {
        cin >> input[i];
    }

    int i = len;
    for (int k = 0; k < (i + 1) / 2; k++)
    {
        int now = k + (i + 1) / 2;
        cout << input[k];
        if (now < i)
        {
            cout << input[now];
        }
    }

    // for (int k = (i + 1) / 2; k < i; k++)
    // {
    //     cout << input[k];
    // }

    cout << endl;
}

int main()
{

    int i = 0, choice;
    cout << "1: encoder 2: decoder 3: quit :";
    cin >> choice;
    while (1)
    {
        if (choice == 3)
            break;

        switch (choice)
        {
        case 1:
            encoder();
            break;
        case 2:
            decoder();
            break;
        default:
            cout << "invalid input" << endl;
            break;
        }
        cout << endl;
        cout << "1: encoder 2: decoder 3: quit :";
        cin >> choice;
    }

    return 0;
}
