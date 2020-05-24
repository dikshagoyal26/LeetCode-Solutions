/** 
Title :   Construct Binary Search Tree from Preorder Traversal
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/
Idea  :   Recursion
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
    TreeNode *bst(vector<int> &preorder, int &pos, int min_val, int max_val)
    {
        if (pos == preorder.size())
        {
            return NULL;
        }
        int current_val = preorder[pos];
        if (current_val > max_val || current_val < min_val)
        {
            return NULL;
        }
        pos++;
        TreeNode *root = new TreeNode(val);
        root->left = bst(preorder, pos, min_val, current_val);
        root->right = bst(preorder, pos, current_val, max_val);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() < 1)
        {
            return NULL;
        }
        int pos = 0;
        return bst(preorder, pos, INT_MIN, INT_MAX);
    }
};