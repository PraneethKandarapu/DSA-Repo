#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor)
{
    // color the curr node with currColor
    color[curr] = currColor;

    // start checking for its adjacent nodes
    for (int &v : adj[curr])
    {

        // if the adjacent node is not colored
        if (color[v] == -1)
        {
            color[v] = 1 - currColor;                                // switch the curr color and color the adjacent node
            if (checkBipartiteDFS(adj, v, color, color[v]) == false) // recursively check for its adjacent node
                return false;
        }
        // if one of its adjacent node is already colored with curr node color
        //  return false
        if (color[curr] == color[v])
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> color(n, -1);

    // we use a loop to check for graph with disconnected components
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