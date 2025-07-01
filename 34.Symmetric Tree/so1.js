function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    return check(root.left, root.right);
};

function check(n1,n2){
    if(n1 == null && n2 == null) return true;
    if(n1 == null || n2 == null || n1.val !== n2.val) return false;

    return check(n1.left, n2.right) && check(n1.right, n2.left);
}
