#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor)
{
    color[curr] = currColor;
    for (int &v : adj[curr])
    {
        if (color[curr] == color[v])
            return false;
        if (color[v] == -1)
        {
            color[v] = 1 - currColor;
            if (checkBipartiteDFS(adj, v, color, color[v]) == false)
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (checkBipartiteDFS(adj, i, color, 1) == false)
                return false;
        }
    }
    return true;
}
int main()
{

    vector<vector<int>> adj = {
        {1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << isBipartite(adj);
}