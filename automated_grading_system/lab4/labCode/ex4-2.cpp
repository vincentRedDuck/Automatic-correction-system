#include <iostream>
#include <cmath>
#include <iomanip>

// #define PI 3.1415926

using namespace std;

float Rectangle(float L, float W)
{
    return 2 * (L + W);
}

float Square(float L)
{
    return 4 * L;
}

float Triangle(float B, float H)
{
    float edge;
    edge = sqrt(pow(B / 2, 2) + pow(H, 2));
    return 2 * edge + B;
}

void PrintRectangle(float L, float W)
{
    int _L = L, _W = W;
    for (int i = 0; i <= _W + 1; i++)
    {

        if (i == 0 || i == _W + 1)
            for (int j = 0; j < _L; j++)
                cout << "-";
        else
        {
            cout << "|";
            for (int k = 1; k < _L - 1; k++)
                cout << " ";
            cout << "|";
        }
        cout << endl;
    }
}

void PrintSquare(float L)
{
    int _L = L;
    for (int i = 0; i <= _L + 1; i++)
    {

        if (i == 0 || i == _L + 1)
            for (int j = 0; j < _L; j++)
                cout << "-";
        else
        {
            cout << "|";
            for (int k = 1; k < _L - 1; k++)
                cout << " ";
            cout << "|";
        }
        cout << endl;
    }
}

int main()
{
    while (1)
    {
        cout << "====================" << endl;
        cout << "1.Rectangle 2.Square 3.Isosceles triangle 4.Exit" << endl;
        cout << "Choose the type of perimeter you want to calculate:" << endl;
        int type;
        cin >> type;
        switch (type)
        {
        case 1:
        {
            cout << "Please enter the Length and Width respectively." << endl;
            float L, W;
            cin >> L >> W;
            cout << "The perimeter if a rectangle with (Length, Width) = (" << fixed << setprecision(3) << L;
            cout << ", " << fixed << setprecision(3) << W << ") is ";
            cout << fixed << setprecision(3) << Rectangle(L, W) << endl;
            PrintRectangle(L, W);
        }
        break;
        case 2:
        {
            cout << "Please enter Length." << endl;
            float L;
            cin >> L;
            cout << "The perimeter of a square with (Length) = (";
            cout << fixed << setprecision(3) << L << ") is ";
            cout << fixed << setprecision(3) << Square(L) << endl;
            PrintSquare(L);
        }
        break;
        case 3:
        {
            cout << "Please enter the Base and Height respectively." << endl;
            float B, H;
            cin >> B >> H;
            cout << "The perimeter of an Isosceles triangle with (Base, Height) = (";
            cout << fixed << setprecision(3) << B;
            cout << ", " << fixed << setprecision(3) << H << ") is ";
            cout << fixed << setprecision(6) << Triangle(B, H) << endl;
        }
        break;
        case 4:
        {
            cout << "Goodbye!" << endl;
        }
        break;
        default:
            cout << "Please follow the instruction carefully." << endl;
        }
        if (type == 4)
            break;
    }

    return 0;
}