/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function (root) {
  function height(node) {
    if (node === null) return 0;

    const leftH = height(node.left);
    const rightH = height(node.right);

    if (Math.abs(leftH - rightH) > 1) return -1;
    if (leftH === -1 || rightH === -1) return -1;
    return Math.max(leftH, rightH) + 1;
  }

  return height(root) === -1;
};
