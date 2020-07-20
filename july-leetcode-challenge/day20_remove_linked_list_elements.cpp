/** 
Title :   Remove Linked List Elements
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/
Idea  :   Checking each node and removing if if val is equal to required value      using two pointer apporach
Time Complexity : O(n) 
*/
/**
    Remove all elements from a linked list of integers that have value val.

    Example:
    Input:  1->2->6->3->4->5->6, val = 6
    Output: 1->2->3->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            head = head->next;
        }
        if (head == NULL)
            return head;
        ListNode *temp = head->next, *prev = head;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                prev->next = temp->next;
                if (prev->next != NULL)
                {
                    temp = prev->next;
                }
                else
                {
                    temp = NULL;
                }
            }
            else
            {
                temp = temp->next;
                prev = prev->next;
            }
        }
        return head;
    }
};