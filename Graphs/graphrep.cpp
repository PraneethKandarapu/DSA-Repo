#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vert, edges;
    cin >> vert >> edges;
    vector<int> adj[vert + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i <= vert; i++)
    {
        cout << i << "->";
        for (auto it : adj[i])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}