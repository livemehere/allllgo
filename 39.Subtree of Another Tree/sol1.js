function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) {
    function isSame(left,right){
      if(left == null && right == null) return true;
      if(left == null || right == null) return false;
      if(left.val !== right.val) return false;
      return isSame(left.left,right.left) && isSame(left.right, right.right);
    }

    function traverse(node, cb){
      if(node == null) return;
      cb(node);
      traverse(node.left,cb);
      traverse(node.right,cb);
    }

    let res = false;
    traverse(root, node=>{
      if(isSame(node, subRoot)){
        res = true;
      }
    })
    return res;
};