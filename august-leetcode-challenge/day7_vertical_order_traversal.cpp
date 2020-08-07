/** 
Title :   Vertical Order Traversal of a Binary Tree
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3415/
Idea  :   BFS
Time Complexity : O(n)
*/
/*
    Given a binary tree, return the vertical order traversal of its nodes values.
    For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
    Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
    If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
    Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

    Example 1:
    Input: [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation: 
    Without loss of generality, we can assume the root node is at position (0, 0):
    Then, the node with value 9 occurs at position (-1, -1);
    The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
    The node with value 20 occurs at position (1, -1);
    The node with value 7 occurs at position (2, -2).

    Example 2:
    Input: [1,2,3,4,5,6,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation: 
    The node with value 5 and the node with value 6 have the same position according to the given scheme.
    However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
    
    Note:
    The tree will have between 1 and 1000 nodes.
    Each node's value will be between 0 and 1000.
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
    map<int, vector<int>> m;

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {{}};
        bfs(root);
        vector<vector<int>> ans;
        for (auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
    void bfs(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int breadth = q.size();
            vector<pair<int, int>> a;
            for (int i = 0; i < breadth; i++)
            {
                auto temp = q.front();
                q.pop();
                a.push_back({temp.first->val, temp.second});
                if (temp.first->left)
                    q.push({temp.first->left, temp.second - 1});
                if (temp.first->right)
                    q.push({temp.first->right, temp.second + 1});
            }
            sort(a.begin(), a.end());
            for (int i = 0; i < a.size(); i++)
                m[a[i].second].push_back(a[i].first);
        }
    }
};