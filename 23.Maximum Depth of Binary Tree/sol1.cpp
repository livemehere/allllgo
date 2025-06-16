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
    int maxDepth(TreeNode *root)
    {
        return getLen(root);
    }
    int getLen(TreeNode *node, int depth = 0)
    {
        if (node == nullptr)
            return depth;
        int left = getLen(node->left, depth);
        int right = getLen(node->right, depth);
        return 1 + std::max(left, right);
    }
};