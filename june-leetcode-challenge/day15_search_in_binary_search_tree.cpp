/** 
Title :   Search in a Binary Search Tree
Link  :   https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3233/
Idea  :   Recursive
Time Complexity : O(n)
*/

/**
  Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL. 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return root;
        else if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};