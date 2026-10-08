#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int v, int source, int dest)
{
    vector<vector<pair<int, int>>> adj(v);
    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int wt = vec[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> result(v, INT_MAX);
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
        parent[i] = i;
    result[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int d = it.second;
            if (d + wt < result[adjNode])
            {
                result[adjNode] = d + wt;
                pq.push({d + wt, adjNode});
                parent[adjNode] = node; // update parent
            }
        }
    }
    if (result[dest] == INT_MAX) // if there is no path
        return {-1};
    vector<int> ans;

    while (parent[dest] != dest) // until the destination becomes the parent
    {
        ans.push_back(dest); // push the destination
        dest = parent[dest]; // change the destination to its parent
    }
    ans.push_back(source);           // push the source
    reverse(ans.begin(), ans.end()); // reverse the array
    return ans;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int source = 3;
    int dest = 1;
    int v = 5;
    vector<int> res = shortestPath(edges, v, source, dest);
    for (int i : res)
        cout << i << " ";
    return 0;
}