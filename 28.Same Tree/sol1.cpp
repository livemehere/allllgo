#include <string>
using std::string;

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        string p_str = "";
        string q_str = "";
        traverse(p, p_str);
        traverse(q, q_str);
        return p_str == q_str;
    }

    void traverse(TreeNode *node, string &res)
    {
        if (node == nullptr)
        {
            res += "null";
            return;
        }
        else
        {
            res += std::to_string(node->val);
        }

        traverse(node->left, res);
        traverse(node->right, res);
    }
};