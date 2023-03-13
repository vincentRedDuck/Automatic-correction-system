#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int **New2DArray(const int N)
{
    int **mat = new int *[N];
    for (int i = 0; i < N; i++)
        mat[i] = new int[N];
    return mat;
}

void Initial2DArray(int **mat, const int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = 0;
}

void DisplaySpiralArray(int **mat, const int N)
{
    int i = 1, j = 1, k = 1, flag = 1;
    while (k <= N * N)
    {
        while (j <= N)
        {
            if (!mat[i][j])
            {
                mat[i][j++] = k++;
                k++;
                if (k > N * N && flag)
                {
                    k = 2;
                    flag = 0;
                }
                if (k > N * N && !flag)
                    break;
            }
            else
                break;
        }
        j--;
        i++;
        while (i <= N)
        {
            if (!mat[i][j])
            {
                mat[i++][j] = k++;
                k++;
                if (k > N * N && flag)
                {
                    k = 2;
                    flag = 0;
                }
                if (k > N * N && !flag)
                    break;
            }
            else
                break;
        }
        i--;
        j--;
        while (j > 0)
        {
            if (!mat[i][j])
            {
                mat[i][j--] = k++;
                k++;
                if (k > N * N && flag)
                {
                    k = 2;
                    flag = 0;
                }
                if (k > N * N && !flag)
                    break;
            }
            else
                break;
        }
        j++;
        i--;
        while (i > 0)
        {
            if (!mat[i][j])
            {
                mat[i--][j] = k++;
                k++;
                if (k > N * N && flag)
                {
                    k = 2;
                    flag = 0;
                }
                if (k > N * N && !flag)
                    break;
            }
            else
                break;
        }
        i++;
        j++;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            cout << setw(5) << right << mat[i][j];
        cout << endl;
    }
}
int main()
{
    int N, i = 1, j = 1, k = 1;
    while (1)
    {
        cin >> N;
        if (N == -1)
            break;
        int **mat = New2DArray(51);
        Initial2DArray(mat, 51);
        DisplaySpiralArray(mat, N);
    }
    return 0;
}