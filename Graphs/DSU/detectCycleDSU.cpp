#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ranks;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unionSet(int x, int y)
{
    int x_par = find(x);
    int y_par = find(y);
    if (x_par == y_par)
        return;
    else if (ranks[x_par] > ranks[y_par])
        parent[y_par] = x_par;
    else if (ranks[y_par] > ranks[x_par])
        parent[x_par] = y_par;
    else
    {
        parent[x_par] = y_par;
        ranks[y_par] += 1;
    }
}

bool detectCycleDSU(vector<vector<int>> &adj, int V)
{

    parent.resize(V);
    ranks.resize(V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    for (int u = 0; u < V; u++)
    {
        for (int &v : adj[u])
        {
            if (u < v)
            {
                int u_par = find(u);
                int v_par = find(v);
                if (u_par == v_par)
                    return true;
                else
                    unionSet(u, v);
            }
        }
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
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << detectCycleDSU(adj, vert);
}