#include <bits/stdc++.h>
using namespace std;
/*


*/

vector<int> dijkstraSet(vector<vector<int>> &edges, int v, int src)
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
    set<pair<int, int>> st; // stores elements in ascending order
    vector<int> result(v, INT_MAX);
    result[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        auto it = *st.begin(); //* for exact value
        int wt = it.first;
        int node = it.second;
        st.erase(it);
        for (auto &vec : adj[node])
        {
            int adjNode = vec.first;
            int d = vec.second;
            if (d + wt < result[adjNode])
            {
                if (result[adjNode] != INT_MAX)
                {
                    // if we are replacing the ans with a better ans, remove the old ans from the set
                    st.erase({result[adjNode], adjNode});
                }
                result[adjNode] = d + wt;
                st.insert({d + wt, adjNode});
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int src = 0;
    int v = 5;

    vector<int> res = dijkstraSet(edges, v, src);
    for (int i : res)
        cout << i << " ";
    return 0;
}