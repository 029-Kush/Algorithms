#include <iostream>
#include <climits>
using namespace std;

#define n 6

int main()
{
    int rank[] = {30, 35, 15, 5, 10, 20, 25};
    int c[n][n] = {0};
    int i, j, k, diff, q;

    for (i = 0; i < n; i++)
        c[i][i] = 0;

    for (diff = 2; diff <= n; diff++)
    {
        for (i = 0; i < n - diff + 1; i++)
        {
            j = i + diff - 1;
            int min = INT_MAX;

            for (k = i; k <= j - 1; k++)
            {
                q = c[i][k] + c[k + 1][j] + rank[i] * rank[k + 1] * rank[j + 1];
                if (q < min)
                    min = q;
            }
            c[i][j] = min;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "the total cost is " << c[0][n - 1];

    return 0;
}