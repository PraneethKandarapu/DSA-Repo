#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vert, edges;
    cin >> vert >> edges;
    vector<int> inDegree(vert, 0);
    queue<int> q;

    vector<vector<int>> adj(vert);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        // directed graph
        adj[u].push_back(v);
    }

    // fill indegree
    for (int i = 0; i < vert; i++)
    {
        for (int &v : adj[i])
            inDegree[v]++;
    }

    // push nodes with indegree(0)
    for (int i = 0; i < vert; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> res;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for (int &v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    for (int u : res)
        cout << u << " ";

    return 0;
}