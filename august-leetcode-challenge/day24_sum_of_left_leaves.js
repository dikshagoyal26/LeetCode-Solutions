/** 
Title :   Sum of Left Leaves    
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3435/
Idea  :   Recursion
Time Complexity : O(n)
*/
/*
    Find the sum of all left leaves in a given binary tree.

    Example:

        3
       / \
      9  20
        /  \
       15   7

    There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24. 
*/

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
 * @return {number}
 */
var sumOfLeftLeaves = function (root) {
    if (!root) return 0;
    let sum = 0;
    let helper = function (node) {
        if (!node) return;
        if (node.left && !node.left.left && !node.left.right) {
            sum += node.left.val;
        }
        helper(node.left);
        helper(node.right);
    }

    helper(root);
    return sum;
};