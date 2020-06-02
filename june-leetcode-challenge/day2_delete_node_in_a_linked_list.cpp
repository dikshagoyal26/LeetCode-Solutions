/** 
Title :   Delete Node in a Linked List
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3348/
Idea  :   Swap with Next Node
Time Complexity : O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};