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

vector<int> leftSideView(TreeNode *root);
vector<int> leftSideView(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        TreeNode *node = q.front();
        ans.push_back(node->val);
        while (n--)
        {
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> ans = leftSideView(root);

    for (int node : ans)
        cout << node << " ";
    return 0;
}
