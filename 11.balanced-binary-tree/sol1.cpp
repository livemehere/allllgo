#include <cstdlib>
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
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode *node, int depth = 0)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr))
            return depth;
        int l = node->left != nullptr ? getHeight(node->left, depth + 1) : depth;
        int r = node->right != nullptr ? getHeight(node->right, depth + 1) : depth;
        if (l == -1 || r == -1)
            return -1;
        if (std::abs(l - r) > 1)
            return -1;
        return std::max(l, r);
    }
};