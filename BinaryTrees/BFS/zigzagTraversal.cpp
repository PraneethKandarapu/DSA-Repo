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
vector<vector<int>> zigzagTraversal(TreeNode *root);
vector<vector<int>> zigzagTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;

    bool leftRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        if (!leftRight)
            reverse(level.begin(), level.end());
        ans.push_back(level);
        leftRight = !leftRight;
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

    vector<vector<int>> ans = zigzagTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}