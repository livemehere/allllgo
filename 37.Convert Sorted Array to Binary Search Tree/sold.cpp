#include <vector>

using std::vector;

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(0, nums.size() - 1, nums);
    }

    TreeNode *build(int left, int right, vector<int> &nums)
    {
        if (left > right)
            return nullptr;
        int mid = std::floor((left + right) / 2);
        int val = nums[mid];
        TreeNode *node = new TreeNode(val);
        node->left = build(left, mid - 1, nums);
        node->right = build(mid + 1, right, nums);

        return node;
    }
};