/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  if (head?.next == null) return false;
  const visited = new Set();
  let cur = head.next;
  while (cur) {
    if (visited.has(cur)) return true;
    visited.add(cur);
    cur = cur.next;
  }
  return false;
};
