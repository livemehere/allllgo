 #include <cstdlib>
 #include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if(root == NULL) return true;
            return height(root) != -1;
            
        }

        int height(TreeNode* node){
            if(node == nullptr) return 0;
            int leftH = height(node->left);
            int rightH = height(node->right);

            if(leftH == -1 || rightH == -1) return -1;
            if(std::abs(leftH - rightH) > 1) return -1;

            return std::max(leftH,rightH)+1;
        }
    };