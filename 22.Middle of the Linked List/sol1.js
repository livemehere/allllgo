function ListNode(val, next) {
      this.val = (val===undefined ? 0 : val)
      this.next = (next===undefined ? null : next)
}
 
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
   let prev=0;
   let cur = head;
   while(cur){
    const postNode = getNodeFrom(cur,prev);
    const postPostNode = getNodeFrom(cur,prev+1);
    if(postNode == null || postPostNode == null) return cur;     
    prev++; 
    cur = cur.next;
   } 

   function getNodeFrom(node, step){
    let target = node;
    while(step > 0){
        target = target.next;
        if(target == null) return null;
        step--;
    }
    return target;
   }
};