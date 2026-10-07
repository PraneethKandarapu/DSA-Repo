#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstrasAlgo(int v, vector<vector<int>> &edges, int src)
{
    // convert to adjacency list
    vector<vector<pair<int, int>>> adj(v);
    for (auto &it : edges)
    {
        int u = it[0];  // frist node of edge
        int v = it[1];  // second node of edge
        int wt = it[2]; // weight of the edge

        // undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // declare a min heap of pair<int,int> for the source node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // resultant vector
    vector<int> res(v, INT_MAX);

    // cost of going from src->src=0
    res[src] = 0;

    // push {cost , node}
    pq.push({0, src});

    while (!pq.empty())
    {
        // extract the cost and node of the top element of queue
        int d = pq.top().first;
        int node = pq.top().second;

        // pop from priority_queue
        pq.pop();
        for (auto &it : adj[node])
        {
            // find the adjacent node of recently popped node
            int adjNode = it.first;    // node
            int wt = it.second;        // its weight from the popped node
            if (d + wt < res[adjNode]) // if the added cost is less than the previous cost in res array
            {
                res[adjNode] = d + wt;            // swap
                pq.push({res[adjNode], adjNode}); // push
            }
        }
    }
    return res;
}

int main()
{

    // given in question
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int src = 0;
    int v = 5;

    vector<int> res = dijkstrasAlgo(v, edges, src);
    for (int i : res)
        cout << i << " ";
    return 0;
}