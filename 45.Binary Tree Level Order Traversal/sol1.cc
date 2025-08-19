#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int level_size = q.size();
            vector<int> level;

            level.reserve(level_size); // 미리 capacity 를 확보하여, push_back() 마다 복사 제거

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(level);
        }

        return res;
    }
};

int main()
{

    Solution s;
    TreeNode *root = new TreeNode{};

    vector<vector<int>> res = s.levelOrder(root);

    return 0;
}