#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
    }
    return v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
    }
}