#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int V, vector<vector<int>> &adj);
bool dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent);

bool dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        if (visited[v])
            return true;
        if (dfs(v, adj, visited, u)) // u is the parent
            return true;
    }
    return false;
}

bool detectCycle(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dfs(i, adj, visited, -1))
            return true;
    }
    return false;
}

int main()
{
    int vert, edges;
    cin >> vert >> edges;

    vector<vector<int>> adj(vert);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (detectCycle(vert, adj))
        cout << "Cycle detected";
    else
        cout << "No cycle detected";
}