#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 : undirected
        // direction = 1 : directed

        // creaate an edge from u to v

        adj[u].push_back(v);
        if (!direction)
            adj[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
                cout << j << " ";
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter the no. of edges" << endl;
    cin >> n;

    int m;
    Graph g;
    cout << "enter the no. of nodes" << endl;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
}