#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

double findAvg(vector<int> level);
vector<double> avgOfRows(TreeNode *root);
vector<double> avgOfRows(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<double> avgs;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            level.push_back(node->val);
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        avgs.push_back(findAvg(level));
    }
    return avgs;
}

double findAvg(vector<int> level)
{
    double avg = 0;
    for (int val : level)
    {
        avg += val;
    }
    return avg / level.size();
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<double> ans = avgOfRows(root);

    for (double node : ans)
        cout << node << " ";
    return 0;
}