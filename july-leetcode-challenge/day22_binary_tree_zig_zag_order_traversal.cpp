/** 
Title :   Binary Tree Zigzag Level Order Traversal
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
Idea  :   BFS
Time Complexity : O(n) 
*/
/**
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
    / \
    9  20
        /  \
    15   7
    return its zigzag level order traversal as:
    [
    [3],
    [20,9],
    [15,7]
    ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> temp_queue;
        temp_queue.push(root);
        int c = 0;
        while (!temp_queue.empty())
        {
            int s = temp_queue.size();
            vector<int> temp_vector;
            while (s)
            {
                TreeNode *temp_node = temp_queue.front();
                temp_queue.pop();
                temp_vector.push_back(temp_node->val);
                if (temp_node->left)
                    temp_queue.push(temp_node->left);
                if (temp_node->right)
                    temp_queue.push(temp_node->right);
                s--;
            }
            if (c % 2 != 0)
                reverse(temp_vector.begin(), temp_vector.end());
            c++;
            res.push_back(temp_vector);
        }

        return res;
    }
};