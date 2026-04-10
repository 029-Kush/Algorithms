#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20

int cost[MAX][MAX];
int n;

int main()
{
    int i, j, k, c, x, y;
    int max_edges, origin, destin;

    cout << "Enter number of nodes : ";
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cost[i][j] = 999999;
    }

    max_edges = n * (n - 1);

    for(i = 1; i <= max_edges; i++)
    {
        cout << "Enter edge " << i << " (0 0 to quit) : ";
        cin >> origin >> destin;

        if(origin == 0 && destin == 0)
            break;

        if(origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            i--;
        }
        else
        {
            cout << "Enter the cost\n";
            cin >> c;
            cost[origin][destin] = c;
        }
    }

    // Display initial matrix
    cout << "\nInitial Cost Matrix\n";
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << cost[i][j] << "\t";
        cout << endl;
    }

    // Floyd's Algorithm
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= n; k++)
            {
                if(cost[j][k] > cost[j][i] + cost[i][k])
                {
                    cost[j][k] = cost[j][i] + cost[i][k];
                }
            }
        }
    }

    // Display final matrix
    cout << "\nFinal Cost Matrix\n";
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << cost[i][j] << "\t";
        cout << endl;
    }

    return 0;
}