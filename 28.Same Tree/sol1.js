function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    function traverse(node,cb){
        if(node == null){
            cb('null');
            return
        }else{
            cb(node.val);
        }
        traverse(node.left,cb);
        traverse(node.right,cb);
    }    
    
    let pStr = '';
    let qStr = '';
    traverse(p,(v)=> pStr+=v);
    traverse(q,(v)=> qStr+=v);
    return pStr === qStr;
};