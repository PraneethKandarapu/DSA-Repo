#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (int &v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj, visited, st);
    }
    st.push(u);
}

vector<int> topoSort(vector<vector<int>> &adj, int vert)
{
    vector<bool> visited(vert, false);
    stack<int> st;
    for (int i = 0; i < vert; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
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
        // directed graph
        adj[u].push_back(v);
    }
    vector<int> topologicalSort = topoSort(adj, vert);

    for (int n : topologicalSort)
    {
        cout << n << " ";
    }
    return 0;
}