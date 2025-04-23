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

  let slow = head;
  let fast = head.next;
  while (slow !== fast) {
    if (slow == null || fast == null) return false;

    slow = slow.next;
    fast = fast?.next?.next ?? null;
  }
  return true;
};
