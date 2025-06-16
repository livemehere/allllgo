function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
   let max=0;
   /**
    * @param {TreeNode} node 
    */
   function dfs(node){
        if(node == null) return 0;
        const l = dfs(node.left);
        const r = dfs(node.right);
        const path = l+r;
        max = Math.max(max,path);
        return 1 + Math.max(l,r);
   }

    dfs(root);
    return max;;

};
