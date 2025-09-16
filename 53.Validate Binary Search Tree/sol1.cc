#include <climits>

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
    bool dfs(TreeNode *node, long long lower, long long upper)
    {
        if (node == nullptr)
            return true;
        int v = node->val;

        if (v <= lower || v >= upper)
            return false;

        return dfs(node->left, lower, v) && dfs(node->right, v, upper);
    }

    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};