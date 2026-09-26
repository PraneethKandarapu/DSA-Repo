#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> rightView(TreeNode *root);

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans = rightView(root);

    for (int node : ans)
        cout << node << " ";
    return 0;
}

vector<int> rightView(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);
    vector<int> ans;

    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();
        TreeNode *node;
        while (n--)
        {
            node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        ans.push_back(node->val);
    }

    return ans;
}