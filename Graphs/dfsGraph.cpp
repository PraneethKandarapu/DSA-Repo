#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited);
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
{
    cout << "dfs" << endl;
    visited[node] = 1;
    cout << node << " ";

    for (auto it : adj[node])
    {
        if (visited[it] == 0)
            dfs(it, adj, visited);
    }
}

int main()
{
    int vert, edges;
    cin >> vert >> edges;

    vector<vector<int>> adj(vert + 1);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "graph" << endl;

    for (int i = 0; i <= vert; i++)
    {
        cout << i << "->";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    vector<int> visited(vert + 1, 0);

    dfs(1, adj, visited);
}