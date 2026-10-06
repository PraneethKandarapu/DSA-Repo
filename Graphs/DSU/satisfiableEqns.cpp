#include <bits/stdc++.h>
using namespace std;

vector<int> ranks;
vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unionSet(int x, int y)
{
    int x_par = find(x);
    int y_par = find(y);

    if (x_par == y_par)
        return;
    else if (ranks[x_par] > ranks[y_par])
        parent[y_par] = x_par;
    else if (ranks[y_par] > ranks[x_par])
        parent[x_par] = y_par;
    else
    {
        parent[x_par] = y_par;
        ranks[y_par] += 1;
    }
}

bool isEquation(vector<string> &equations)
{
    ranks.resize(26);
    parent.resize(26);

    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    for (string &str : equations)
    {
        if (str[1] == '=')
        {
            unionSet(str[0] - 'a', str[3] - 'a');
        }
    }
    for (string &str : equations)
    {
        if (str[1] == '!')
        {
            char first = str[0] - 'a';
            char sec = str[3] - 'a';

            if (find(first) == find(sec))
                return false;
        }
    }
    return true;
}

int main()
{
    vector<string> equations = {"a==b", "e==c", "b==c", "a==e"};

    cout << isEquation(equations);
}