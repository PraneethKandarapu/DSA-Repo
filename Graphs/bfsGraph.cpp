#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int start)
{
    int vert = adj.size();
    vector<int> visited(vert, 0);
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    cout << "bfs" << endl;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
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
    bfs(adj, 2);
}