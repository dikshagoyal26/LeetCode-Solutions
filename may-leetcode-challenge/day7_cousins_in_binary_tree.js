/** 
Title :  Cousins in Binary Tree
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
Idea  :  BFS traversal and checking if nodes are at same depth but have different parents
Time Complexity : O(N) 
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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */

var isCousins = function (root, x, y) {
    if (root == null) return false;
    let q = [root];
    while (q.length > 0) {
        let size = q.length;
        let foundx = false;
        let foundy = false;
        while (size--) {
            let node = q.shift();

            if (node.left && node.right)
                if ((x == node.left.val && y == node.right.val) || (x == node.right.val && y == node.left.val)) return false;

            if (x == node.val) foundx = true;
            if (y == node.val) foundy = true;
            
            if (node.left) q.push(node.left)
            if (node.right) q.push(node.right)
        }
        if (foundx && foundy) return true;
    }
    return false;
};