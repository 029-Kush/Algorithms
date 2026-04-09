#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[10];
bool visited[10];

bool dfs(int u, int t) {
    if (u == t) return true;

    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, t))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5;

    // undirected graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    int s = 0, t = 4;

    if (dfs(s, t))
        cout << "Path exists from " << s << " to " << t;
    else
        cout << "No path exists";

    return 0;
}