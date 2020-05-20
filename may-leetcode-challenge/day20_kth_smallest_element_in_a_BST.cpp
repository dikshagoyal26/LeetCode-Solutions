/** 
Title :  Kth Smallest Element in a BST
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
Idea  :  Inorder traversal.
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
class Solution {
public:
    int count=0,ans=-1;
    void preorder(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        preorder(root->left,k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        preorder(root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        preorder(root,k);
        return ans;  
    }
};