#include <iostream>

using namespace std;

void Encoder(char[], char[], int);
void Decoder(char[], char[], int);
void DisplaySent(char[], int);

int main()
{
    int choose, length;
    while (1)
    {
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> choose;
        if (choose == 1)
        {
            cout << "Please enter sentences length: ";
            cin >> length;
            char sent[length], res[length];
            cin >> sent;
            Encoder(sent, res, length);
            DisplaySent(res, length);
        }
        else if (choose == 2)
        {
            cout << "Please enter sentences length: ";
            cin >> length;
            char sent[length], res[length];
            cin >> sent;
            Decoder(sent, res, length);
            DisplaySent(res, length);
        }
        else if (choose == 3)
            break;
        else
            cout << "invalid input" << endl
                 << endl;
    }
    return 0;
}

void Encoder(char sent[], char res[], int length)
{
    if (length % 2 == 0)
    {
        for (int i = 0; i < length / 2; i++)
            res[i] = sent[2 * i];
        for (int i = length / 2; i < length; i++)
            res[i] = sent[2 * (i - length / 2 + 1) - 1];
    }
    else
    {
        for (int i = 0; i < (length + 1) / 2; i++)
            res[i] = sent[2 * i];
        for (int i = length / 2; i < length; i++)
            res[i + 1] = sent[2 * (i - length / 2 + 1) - 1];
    }
}

void Decoder(char sent[], char res[], int length)
{
    if (length % 2 == 0)
    {
        for (int i = 0; i < length / 2; i++)
        {
            res[2 * i] = sent[i];
            res[2 * i + 1] = sent[i + length / 2];
        }
    }
    else
    {
        for (int i = 0; i < length / 2 + 1; i++)
            res[2 * i] = sent[i];
        for (int i = 0; i < length / 2; i++)
            res[2 * i + 1] = sent[i + length / 2 + 1];
    }
}

void DisplaySent(char res[], int length)
{
    for (int i = 0; i < length; i++)
        cout << res[i];
    cout << endl
         << endl;
}