 function ListNode(val, next) {
      this.val = (val===undefined ? 0 : val)
      this.next = (next===undefined ? null : next)
  }


/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let prev = null;
    let cur = head;

    while(cur !== null){
        const next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
};