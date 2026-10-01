#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adj, int vert);
bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRec);

bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRec)
{

    visited[u] = true;
    inRec[u] = true;

    for (int &v : adj[u])
    {
        if (!visited[v] && isCycleDFS(v, adj, visited, inRec))
            return true;
        else if (inRec[v] == true)
            return true;
    }
    inRec[u] = false;
    return false;
}
bool isCycle(vector<vector<int>> &adj, int vert)
{
    vector<bool> visited(vert, false);
    vector<bool> inRec(vert, false);

    for (int i = 0; i < vert; i++)
    {
        if (!visited[i] && isCycleDFS(i, adj, visited, inRec))
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
        // directed graph
        adj[u].push_back(v);
    }

    if (isCycle(adj, vert))
        cout << "cycle detected";
    else
        cout << "no cycle detected";
}