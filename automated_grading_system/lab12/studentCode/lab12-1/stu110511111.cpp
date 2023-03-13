#include <iostream>
#include <iomanip>

using namespace std;

int  **createArray(const int);
void initialArray(int **, const int);
void printArray(int **, const int);
void deleteArray(int **, const int);

int main ()
{
    int size = 0;
    cin >> size;
    while (size>0)
    {
        int **A = createArray(size); 
        initialArray(A, size);
        printArray(A, size);
        deleteArray(A, size);
        cin >> size;
    }

    return 0;
}

int **createArray (const int x)
{
    int **tem = new int *[x];
    for (int i=0; i<x; i++)
        {
            tem[i] = new int [x];
        }
    return tem;
}

void initialArray (int **a, const int x)
{
    int cur = 1;
    int m = 0;
    int n = 0;
    int max = 0;
    if (x%2==0)
        max = x*x-1;
    else
        max = x*x;
    if(x==1)
        a[0][0] = 1;
    int round = 0;
    if(x%2==0)
        round = x/2;
    else
        round = (x+1)/2;
    for (int i=0; i<round; i++)
    {
        for (int j=0; j<(x-1-2*i>0?x-1-2*i:1); j++)
        {
            if(x%2==1&&i==round-1)
            {
                a[m][n] = cur;
                continue;
            }
            a[m][n] = cur;
            n++;
            if(cur != max)
                cur+=2;
            else
                cur=2;
        }
        for (int j=0; j<(x-1-2*i>0?x-1-2*i:1); j++)
        {
            if(x%2==1&&i==round-1)
                continue;
            a[m][n] = cur;
            m++;
            if(cur != max)
                cur+=2;
            else
                cur=2;
        }
        for (int j=0; j<(x-1-2*i>0?x-1-2*i:1); j++)
        {
            if(x%2==1&&i==round-1)
                continue;
            a[m][n] = cur;
            n--;
            if(cur != max)
                cur+=2;
            else
                cur=2;
        }
        for (int j=0; j<(x-1-2*i>0?x-1-2*i:1); j++)
        {
            if(x%2==1&&i==round-1)
                continue;
            a[m][n] = cur;
            if (j<(x-1-2*i>0?x-1-2*i-1:0))
            m--;
            else
            n++;
            if(cur != max)
                cur+=2;
            else
                cur=2;
        }
    }

}

void printArray (int **a, const int x)
{
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<x; j++)
        {
            cout << setw(5) << right << a[i][j];
        }
        cout << '\n';
    }
}

void deleteArray (int **a, const int x)
{
    for (int i=0; i<x; i++)
    {
        delete [] a[i];
    }
    delete [] a;
    a = NULL;
}
