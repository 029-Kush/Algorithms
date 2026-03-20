#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int source, dest, wt;
};
int main()
{
    int v, e, start;
    cout << "enter the nr of vertices\n";
    cin >> v;
    cout << "enter the nr of edges\n";
    cin >> e;
    struct edge edges[e];
    float dist[v];
    cout << "enter the source,dest and weight of each edge\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].source >> edges[i].dest >> edges[i].wt;
    cout << "enter the start node\n";
    cin >> start;
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[start - 1] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].source;
            int v = edges[j].dest;
            int w = edges[j].wt;
            if (dist[v - 1] > dist[u - 1] + w)
                dist[v - 1] = dist[u - 1] + w;
        }
        cout << "intermediate output";
        for (int i = 0; i < v; i++)
            cout << dist[i] << " ";
        cout << "\n";
    }
    int flag = 0; // this loop is to check if the graph contains any negative weight cycle
    for (int j = 0; j < e; j++)
    {
        int u = edges[j].source;
        int v = edges[j].dest;
        int w = edges[j].wt;
        if (dist[v - 1] > dist[u - 1] + w)
        {
            cout << "the graph contains negative weight cycle; so nosolution\n ";
                flag = 1;
            break;
        }
    }
    cout << "final output";
    if (flag == 0)
        for (int i = 0; i < v; i++)
            cout << dist[i] << " ";
    return 0;
}