/** 
Title :   Reorder List
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/
Idea  :   DFS
Time Complexity : O(n)
*/
/**
    Given a singly linked list L: L0→L1→…→Ln-1→Ln,
    reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
    You may not modify the values in the list's nodes, only nodes itself may be changed.

    Example 1:
    Given 1->2->3->4, reorder it to 1->4->2->3.
    
    Example 2:
    Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    dfs(head)
};
function dfs(node) {
    if (!node || !node.next || !node.next.next) return
    var end = node
    var next = node.next
    var prev
    while (end.next) {
        prev = end
        end = end.next
    }
    node.next = end
    end.next = next
    prev.next = null
    dfs(next)
}