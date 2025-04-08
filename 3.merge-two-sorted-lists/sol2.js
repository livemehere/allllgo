/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
  let rootNode = new ListNode();
  let leafNode = rootNode;
  let node1 = list1;
  let node2 = list2;

  while (node1 && node2) {
    if (node1.val < node2.val) {
      leafNode.next = node1;
      node1 = node1.next;
    } else {
      leafNode.next = node2;
      node2 = node2.next;
    }
    leafNode = leafNode.next;
  }

  leafNode.next = node1 || node2;

  /** unnecessary chaining rest of nodes, because node already points to the rest of the list */
  // while (rest) {
  //   leafNode.next = rest;
  //   leafNode = leafNode.next;
  //   rest = rest.next;
  // }

  return rootNode.next;
};

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

const n4 = new ListNode(4, undefined);
const n2 = new ListNode(2, n4);
const n1 = new ListNode(1, n2);

const N4 = new ListNode(4, undefined);
const N3 = new ListNode(3, N4);
const N1 = new ListNode(1, N3);

const result = mergeTwoLists(n1, N1);
traverse(result);

function traverse(listNode) {
  let cur = listNode;
  while (cur) {
    console.log(cur.val);
    cur = cur.next;
  }
}
