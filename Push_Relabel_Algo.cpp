#include <bits/stdc++.h>
using namespace std;
struct Vertex
{
    int h;
    int eflow;
};
int v, e;
int **cap, **flow;
struct Vertex *vert;
int getactivenode(int source, int sink)
{
    for (int i = 1; i < v - 1; i++) // consider only the intermediate nodes excluding source & sink
    {
        if (vert[i].eflow > 0) // eflow node
        {
            for (int j = 0; j < v; j++)
            {
                if (cap[i][j] != 0 || flow[i][j] != 0) // check both cap[][] & flow[][] to find the neighbors
                {
                    if (cap[i][j] != flow[i][j]) // check if there is residual capacity
                        return i;
                }
            }
        }
    }
    return -1;
}
void preflow(int s)
{
    vert[s].h = v;
    for (int i = 0; i < v; i++)
    {
        if (i != s && cap[s][i] != 0)
        {
            flow[s][i] = cap[s][i];
            flow[i][s] = -cap[s][i];
            vert[i].eflow += cap[s][i];
        }
    }
}
bool push(int u)
{
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (flow[u][i] == cap[u][i])
                continue;
            if (vert[u].h > vert[i].h)
            { // minimum of residual capacity[u][i] and eflow(u)
                int Flow = cap[u][i] - flow[u][i] < vert[u].eflow ? cap[u][i] - flow[u][i] : vert[u].eflow;
                vert[u].eflow -= Flow;
                vert[i].eflow += Flow;
                flow[u][i] += Flow;
                flow[i][u] -= Flow;
                return true;
            }
        }
    }
    return false;
}
void relabel(int u)
{
    int minh = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (cap[u][i] == flow[u][i])
                continue;
            if (vert[i].h < minh) // at the end of loop, height of least height node is considered
            {
                minh = vert[i].h;
                vert[u].h = minh + 1;
            }
        }
    }
}
int maxFlow(int source, int sink)
{
    preflow(source);
    cout << "\nInitial capacity\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << cap[i][j] << " ";
        cout << "\n";
    }