#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned long long factorial(int x)
{
    unsigned long long ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= i;
    }

    return ans;
}

double SumOfReciprocal_S1(int x)
{
    double ans = 0;
    for (int i = 1; i <= x; i++)
    {
        ans += 1.0 / i;
    }

    return ans;
}

double SumOfReciprocal_S2(int x)
{
    double ans = 1.0;
    double tmp = 1.0;
    for (int i = 2; i <= x; i++)
    {
        ans += tmp / i;
        tmp /= i;
    }

    return ans;
}

int main()
{
    while (1)
    {
        cout << "Enter an integer value for the number of order n" << endl;
        int n;
        cin >> n;
        // cout << "Factorial = " << factorial(n) << endl;
        if (n == 0)
        {
            cout << "exit" << endl;
            break;
        }
        else
        {
            cout << "The results of S1 snd S2 are:" << endl;
            cout << "S1 = ";
            cout << fixed << setprecision(9) << SumOfReciprocal_S1(n) << endl;
            cout << "S2 = ";
            cout << fixed << setprecision(9) << SumOfReciprocal_S2(n) << endl;
        }
    }
    return 0;
}