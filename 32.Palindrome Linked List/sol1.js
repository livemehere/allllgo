function ListNode(val, next) {
     this.val = (val===undefined ? 0 : val)
     this.next = (next===undefined ? null : next)
}

 /**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let res = '';
    let cur = head;
    while(cur){
        res+= `${cur.val}`;
        cur = cur.next;
    }
    const reverse = res.split('').reverse().join('');
    return res === reverse;
};