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

vector<int> largestVal(TreeNode *root);
vector<int> largestVal(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->val > maxVal)
                maxVal = node->val;
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        ans.push_back(maxVal);
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
    vector<int> ans = largestVal(root);

    for (int node : ans)
        cout << node << " ";
    return 0;
}