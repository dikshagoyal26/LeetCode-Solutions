/** 
Title :  Cousins in Binary Tree
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
Idea  :  BFS traversal and checking if nodes are at same depth but have different parents
Time Complexity : O(N) 
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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int foundx = false;
            int foundy = false;
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && node->right)
                    if ((x == node->left->val && y == node->right->val) || (x == node->right->val && y == node->left->val))
                        return false;

                if (x == node->val)
                    foundx = true;
                if (y == node->val)
                    foundy = true;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (foundx && foundy)
                return true;
        }
        return false;
    }
};