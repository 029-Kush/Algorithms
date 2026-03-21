#include <bits/stdc++.h>
using namespace std;

#define V 6  // number of vertices

// DFS to find augmenting path
bool dfs(int rGraph[V][V], int s, int t, bool visited[], int parent[])
{
    visited[s] = true;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && rGraph[s][v] > 0)
        {
            parent[v] = s;
            if (v == t)
                return true;
            if (dfs(rGraph, v, t, visited, parent))
                return true;
        }
    }
    return false;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int rGraph[V][V]; // residual graph

    // copy original graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];

    int parent[V];
    int max_flow = 0;

    // while there is a path from source to sink
    while (true)
    {
        bool visited[V] = {false};

        if (!dfs(rGraph, s, t, visited, parent))
            break;

        // find minimum capacity in path
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual graph
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "Max Flow: " << fordFulkerson(graph, 0, 5);

    return 0;
}