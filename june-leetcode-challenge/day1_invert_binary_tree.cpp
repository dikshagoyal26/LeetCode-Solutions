/** 
Title :   Invert Binary Tree
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3347/
Idea  :   Swapping the childs of each node
Time Complexity : O(n)
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
    void invert(TreeNode *root)
    {
        if (root == NULL || (!root->left && !root->right))
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};
