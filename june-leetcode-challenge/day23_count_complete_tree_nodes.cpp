/** 
Title :   Count Complete Tree Nodes
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3369/
Idea  :   dfs
Time Complexity : O(n)
*/
/**
 * Given a complete binary tree, count the number of nodes.
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
    int countNodes(TreeNode *root)
    {
        return !root ? 0 : ((root->left ? countNodes(root->left) : 0) + (root->right ? countNodes(root->right) : 0) + 1);
    }
};
