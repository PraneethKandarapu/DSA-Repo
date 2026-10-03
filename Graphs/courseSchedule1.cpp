#include <bits/stdc++.h>
using namespace std;

int main()
{

    int vert, edges;
    cin >> vert >> edges;
    vector<vector<int>> adj(vert);
    vector<int> inDeg(vert, 0);
    queue<int> q;
    int count = 0;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        // directed graph
        adj[u].push_back(v);
    }
    for (int i = 0; i < vert; i++)
    {
        for (int &v : adj[i])
        {
            inDeg[v]++;
        }
    }
    for (int i = 0; i < vert; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
            count++;
        }
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
            {
                q.push(v);
                count++;
            }
        }
    }

    if (count == vert)
        cout << "true";
    else
        cout << "false";
    return 0;
}