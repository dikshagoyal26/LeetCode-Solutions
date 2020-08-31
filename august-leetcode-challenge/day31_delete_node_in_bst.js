/**
Title :   Delete Node in a BST
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3443/
Idea  :   recursion
Time Complexity : O(h)
*/
/*
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
    Basically, the deletion can be divided into two stages:
    Search for a node to remove.
    If the node is found, delete the node.
    Note: Time complexity should be O(height of tree).

    Example:
    root = [5,3,6,2,4,null,7]
    key = 3

         5
        / \
       3   6
      / \   \
     2   4   7

    Given key to delete is 3. So we find the node with value 3 and delete it.
    One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
         5
        / \
       4   6
      /     \
     2       7
    Another valid answer is [5,2,6,null,4,null,7].

        5
       / \
      2   6
       \   \
        4   7
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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function (root, key) {
    return dl(root, key)
};
function dl(root, key) {
    if (!root) return root;

    if (root.val < key) {
        root.right = dl(root.right, key)
    }

    if (root.val > key) {
        root.left = dl(root.left, key)
    }

    if (root.val === key) {
        if (!root.left && !root.right) {
            root = null;
        }
        else if (!root.left) {
            root = root.right;
        }
        else if (!root.right) {
            root = root.left;
        }
        else {
            let node = getMin(root.right);
            root.val = node.val;
            root.right = dl(root.right, node.val);
        }
    }
    return root;
}
function getMin(root) {
    let current = root;
    while (current.left) {
        current = current.left;
    }
    return current;
}
