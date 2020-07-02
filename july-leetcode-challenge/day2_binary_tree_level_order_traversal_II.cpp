/** 
Title :   Binary Tree Level Order Traversal II
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/
Idea  :   BFS
Time Complexity : O(n)
*/
/**
    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
         3
        / \
       9  20
         /  \
        15   7
    return its bottom-up level order traversal as:
        [
        [15,7],
        [9,20],
        [3]
        ]
 * /
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        stack<vector<int>> st;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            while (s--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node == NULL)
                    continue;

                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            st.push(temp);
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};