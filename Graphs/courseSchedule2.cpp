#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vert, edges;
    cin >> vert >> edges;
    vector<int> inDeg(vert, 0);

    vector<vector<int>> adj(vert);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        // directed graph
        adj[u].push_back(v);
        // populating the indeg array
        inDeg[v]++;
    }
    queue<int> q;

    // push nodes with indeg=0
    for (int i = 0; i < vert; i++)
    {
        if (inDeg[i] == 0)
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
            inDeg[v]--;
            if (inDeg[v] == 0)
                q.push(v);
        }
    }

    if (res.size() == vert)
    {
        for (int node : res)
            cout << node << " ";
    }
    else
    {
        cout << "{}";
    }
    return 0;
}