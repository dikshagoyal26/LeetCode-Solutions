/** 
Title :   Construct Binary Tree from Inorder and Postorder Traversal
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/
Idea  :   Recursion
Time Complexity : O(n) 
*/
/**
    Given inorder and postorder traversal of a tree, construct the binary tree.
    Note:
    You may assume that duplicates do not exist in the tree.

    For example, given
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode *AddNode(vector<int> &inorder, vector<int> &postorder, int inleft, int inright, int postroot)
    {
        if (inleft > inright)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postroot]);

        int inroot = inright;
        while (inorder[inroot] != postorder[postroot])
            inroot--;

        root->left = AddNode(inorder, postorder, inleft, inroot - 1, postroot - (inright - inroot) - 1);
        root->right = AddNode(inorder, postorder, inroot + 1, inright, postroot - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return AddNode(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};