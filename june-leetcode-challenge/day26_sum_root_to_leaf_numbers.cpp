/** 
Title :   Sum Root to Leaf Numbers
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
Idea  :   DFS
Time Complexity : O(n)
*/
/**
    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
    An example is the root-to-leaf path 1->2->3 which represents the number 123.
    Find the total sum of all root-to-leaf numbers.
    Note: A leaf is a node with no children. 
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
    int totalSum = 0;
    void summ(TreeNode *root, int lastSum)
    {
        if (root == NULL)
            return;
        lastSum = 10 * lastSum + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            totalSum += lastSum;
            return;
        }
        summ(root->left, lastSum);
        summ(root->right, lastSum);
    }
    int sumNumbers(TreeNode *root)
    {
        totalSum = 0;
        summ(root, 0);
        return totalSum;
    }
};