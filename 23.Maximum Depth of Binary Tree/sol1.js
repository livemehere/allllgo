function TreeNode(val, left, right) {
      this.val = (val===undefined ? 0 : val)
      this.left = (left===undefined ? null : left)
      this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
 function getLen(node,depth = 0){
    if(node == null) return depth;
    const left = getLen(node.left,depth);
    const right = getLen(node.right, depth);
    return 1 + Math.max(left,right);
 }   
return getLen(root)
};