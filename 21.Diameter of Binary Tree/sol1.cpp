#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int max = 0;
        dfs(root, max);
        return max;
    }

    int dfs(TreeNode *root, int &max)
    {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left, max);
        int r = dfs(root->right, max);
        return 1 + std::max(l, r);
    }
};