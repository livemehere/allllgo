function TreeNode(val, left, right) {
     this.val = (val===undefined ? 0 : val)
     this.left = (left===undefined ? null : left)
     this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    return getHeight(root) !== -1;
};

function getHeight(node, depth = 0){
    if(!node || (!node.left && !node.right)) return depth; 
    const l = node.left ? getHeight(node.left, depth+1) : depth; 
    const r = node.right ? getHeight(node.right, depth+1) : depth;
    if(l == -1 || r == -1) return -1;
    if(Math.abs(l-r) > 1) return -1;
    return Math.max(l,r);
}