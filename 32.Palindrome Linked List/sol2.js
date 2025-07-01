
 /**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let res = [];
    let cur = head;
    while(cur){
        res.push(cur.val);
        cur = cur.next;
    }
    const resVal = res.join('');
    return resVal === res.reverse().join('');
};